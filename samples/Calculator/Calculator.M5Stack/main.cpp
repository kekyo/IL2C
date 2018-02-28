#include <M5Stack.h>
#include <il2c.h>

//////////////////////////////////////////////////////////////////////////

extern "C" bool twtoi(const wchar_t *_Str, int32_t* value)
{
    bool sign = false;

    for (;; _Str++)
    {
        wchar_t ch = *_Str;
        if ((ch == L' ') || (ch == L'\t'))
        {
            continue;
        }

        if (ch == L'-')
        {
            sign = true;
            _Str++;
        }
        else if (ch == L'+')
        {
            _Str++;
        }
        else if ((*_Str < L'0') || (*_Str > L'9'))
        {
            return false;
        }

        break;
    }

    int32_t n = 0;
    while ((*_Str >= L'0') && (*_Str <= L'9'))
    {
        n = n * 10 + *_Str++ - L'0';
    }

    *value = sign ? -n : n;
    return true;
}

extern "C" void itow(int32_t value, wchar_t* p)
{
    wchar_t *j;
    wchar_t b[6];

    if (value < 0)
    {
        *p++ = L'-';
        value = -value;
    }

    j = &b[5];
    *j-- = 0;

    do
    {
        *j-- = value % 10 + L'0';
        value /= 10;
    } while (value);

    do
    {
        *p++ = *++j;
    } while (*j);
}

//////////////////////////////////////////////////////////////////////////

#include "driver/i2c.h"

/* i2c - Example
   For other examples please check:
   https://github.com/espressif/esp-idf/tree/master/examples
   This example code is in the Public Domain (or CC0 licensed, at your option.)
   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#define DATA_LENGTH                        512              /*!<Data buffer length for test buffer*/
#define RW_TEST_LENGTH                     129              /*!<Data length for r/w test, any value from 0-DATA_LENGTH*/
#define DELAY_TIME_BETWEEN_ITEMS_MS        1234             /*!< delay time between different test items */

#define I2C_KEYBOARD_SCL_IO          19               /*!< gpio number for I2C master clock */
#define I2C_KEYBOARD_SDA_IO          18               /*!< gpio number for I2C master data  */
#define I2C_KEYBOARD_NUM             I2C_NUM_0        /*!< I2C port number for master dev */
#define I2C_KEYBOARD_TX_BUF_DISABLE  0                /*!< I2C master do not need buffer */
#define I2C_KEYBOARD_RX_BUF_DISABLE  0                /*!< I2C master do not need buffer */
#define I2C_KEYBOARD_FREQ_HZ         100000           /*!< I2C master clock frequency */
#define I2C_KEYBOARD_ADDR            0x88

#define ESP_SLAVE_ADDR                     0x28             /*!< ESP32 slave address, you can set any 7bit value */
#define WRITE_BIT                          I2C_MASTER_WRITE /*!< I2C master write */
#define READ_BIT                           I2C_MASTER_READ  /*!< I2C master read */
#define ACK_CHECK_EN                       0x1              /*!< I2C master will check ack from slave*/
#define ACK_CHECK_DIS                      0x0              /*!< I2C master will not check ack from slave */
#define ACK_VAL                            0x0              /*!< I2C ack value */
#define NACK_VAL                           0x1              /*!< I2C nack value */

// SemaphoreHandle_t print_mux = NULL;

void i2c_keyboard_master_init()
{
    int i2c_master_port = I2C_KEYBOARD_NUM;
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = GPIO_NUM_21;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = GPIO_NUM_22;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_KEYBOARD_FREQ_HZ;
    i2c_param_config((i2c_port_t)i2c_master_port, &conf);
    i2c_driver_install((i2c_port_t)i2c_master_port, conf.mode,
                       I2C_KEYBOARD_RX_BUF_DISABLE,
                       I2C_KEYBOARD_TX_BUF_DISABLE, 0);
}

/**
 * @brief test code to write esp-i2c-slave
 *
 * 1. set mode
 * _________________________________________________________________
 * | start | slave_addr + wr_bit + ack | write 1 byte + ack  | stop |
 * --------|---------------------------|---------------------|------|
 * 2. wait more than 24 ms
 * 3. read data
 * ______________________________________________________________________________________
 * | start | slave_addr + rd_bit + ack | read 1 byte + ack  | read 1 byte + nack | stop |
 * --------|---------------------------|--------------------|--------------------|------|
 */
uint8_t i2c_keyboard_read()
{
    uint8_t ret;
    // i2c_port_t i2c_num = I2C_KEYBOARD_NUM;
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (uint8_t)(I2C_KEYBOARD_ADDR << 1) | READ_BIT, ACK_CHECK_EN);
    i2c_master_read_byte(cmd, &ret, (i2c_ack_type_t)NACK_VAL);
    i2c_master_stop(cmd);
    i2c_master_cmd_begin(I2C_KEYBOARD_NUM, cmd, 1000 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}

//////////////////////////////////////////////////////////////////////////

// The scrolling area must be a integral multiple of TEXT_HEIGHT
#define TEXT_HEIGHT 16 // Height of text to be printed and scrolled
#define TOP_FIXED_AREA 14 // Number of lines in top fixed area (lines counted from top of screen)
#define BOT_FIXED_AREA 0 // Number of lines in bottom fixed area (lines counted from bottom of screen)
#define YMAX 240 // Bottom of screen area

class M5_Terminal
{
private:
    // The initial y coordinate of the top of the scrolling area
    uint16_t yStart;
    // yArea must be a integral multiple of TEXT_HEIGHT
    uint16_t yArea;
    // The initial y coordinate of the top of the bottom text line
    // uint16_t yDraw = YMAX - BOT_FIXED_AREA - TEXT_HEIGHT;
    uint16_t yDraw;

    // Keep track of the drawing x coordinate
    uint16_t xPos;

    // For the byte we read from the serial port
    byte data;

    // A few test variables used during debugging
    boolean change_colour;
    boolean selected;

    // We have to blank the top line each time the display is scrolled, but this takes up to 13 milliseconds
    // for a full width line, meanwhile the serial buffer may be filling... and overflowing
    // We can speed up scrolling of short text lines by just blanking the character we drew
    //int blank[19]; // We keep all the strings pixel lengths to optimise the speed of the top line blanking

    // ##############################################################################################
    // Setup the vertical scrolling start address pointer
    // ##############################################################################################
    void scrollAddress(uint16_t vsp)
    {
        M5.Lcd.writecommand(ILI9341_VSCRSADD); // Vertical scrolling pointer
        M5.Lcd.writedata(vsp>>8);
        M5.Lcd.writedata(vsp);
    }

    // ##############################################################################################
    // Call this function to scroll the display one text line
    // ##############################################################################################
    int scroll_line()
    {
        int yTemp = yStart; // Store the old yStart, this is where we draw the next line
        // Use the record of line lengths to optimise the rectangle size we need to erase the top line
        // M5.Lcd.fillRect(0,yStart,blank[(yStart-TOP_FIXED_AREA)/TEXT_HEIGHT],TEXT_HEIGHT, TFT_BLACK);
        M5.Lcd.fillRect(0,yStart,320,TEXT_HEIGHT, TFT_BLACK);

        // Change the top of the scroll area
        yStart+=TEXT_HEIGHT;
        // The value must wrap around as the screen memory is a circular buffer
        // if (yStart >= YMAX - BOT_FIXED_AREA) yStart = TOP_FIXED_AREA + (yStart - YMAX + BOT_FIXED_AREA);
        if (yStart >= YMAX) yStart = 0;
        // Now we can scroll the display
        scrollAddress(yStart);
        return  yTemp;
    }

    // ##############################################################################################
    // Setup a portion of the screen for vertical scrolling
    // ##############################################################################################
    // We are using a hardware feature of the display, so we can only scroll in portrait orientation
    void setupScrollArea(uint16_t tfa, uint16_t bfa)
    {
        M5.Lcd.writecommand(ILI9341_VSCRDEF); // Vertical scroll definition
        M5.Lcd.writedata(tfa >> 8);           // Top Fixed Area line count
        M5.Lcd.writedata(tfa);
        M5.Lcd.writedata((YMAX-tfa-bfa)>>8);  // Vertical Scrolling Area line count
        M5.Lcd.writedata(YMAX-tfa-bfa);
        M5.Lcd.writedata(bfa >> 8);           // Bottom Fixed Area line count
        M5.Lcd.writedata(bfa);
    }

public:
    M5_Terminal()
        : yStart(0), yArea(YMAX-TOP_FIXED_AREA-BOT_FIXED_AREA),
        yDraw(0), xPos(0), data(0), change_colour(1), selected(1)
    {
        //memset(blank, 0, sizeof blank);
    }

    void clear()
    {
        M5.Lcd.fillScreen(TFT_BLACK);
        M5.Lcd.setWindow(0, 0, 320, 240);
        M5.Lcd.setCursor(0, 0, 2);
        M5.Lcd.setTextColor(TFT_WHITE,TFT_BLACK);  
        M5.Lcd.setTextSize(1);

        setupScrollArea(0, 0);
    }

    void feed()
    {
        xPos = 0;
        yDraw = scroll_line(); // It can take 13ms to scroll and blank 16 pixel lines
    }

    void drawChar(wchar_t ch)
    {
        // If it is a CR or we are near end of line then scroll one line
        if (ch == '\r' || xPos > 311)
        {
            feed();
        }
        if (ch > 31)
        {
            xPos += M5.Lcd.drawChar(ch, xPos, yDraw, 2);
            // blank[(18+(yStart-TOP_FIXED_AREA)/TEXT_HEIGHT)%19]=xPos; // Keep a record of line lengths
        }
    }
};

//////////////////////////////////////////////////////////////////////////

static M5_Terminal terminal;

extern "C" void Write(const wchar_t* pMessage)
{
  for (int index = 0; pMessage[index] != 0; index++)
  {
    wchar_t ch = pMessage[index];
    terminal.drawChar(ch);
  }
}

extern "C" void WriteLine(const wchar_t* pMessage)
{
  Write(pMessage);
  terminal.feed();
}

extern "C" void WriteLineToError(const wchar_t* pMessage)
{
}

extern "C" void ReadLine(wchar_t* pBuffer, uint16_t length)
{
    int index = 0;
    while (index < (length - 1))
    {
        wchar_t ch = i2c_keyboard_read();
        if (ch == L'\0')
        {
            delay(100);
            M5.update();
            continue;
        }

        // For calculator FACES specifics:
        if (ch == L'`')
        {
            // [+/-] --> [SPACE]
            ch = L' ';
        }
        if ((ch == L'A') || (ch == L'\b'))
        {
            // [AC] --> [BS]
            // [AC] --> [BS] (long)
            ch = L'\b';
        }
        if ((ch == L'=') || (ch == L'\r'))
        {
            // [=] --> [LF]
            // [=] --> [LF] (long)
            ch = L'\n';
        }

        if (ch == L'\n')
        {
            terminal.feed();
            break;
        }

        terminal.drawChar(ch);
        pBuffer[index++] = ch;
    }

    pBuffer[index] = L'\0';
}

//////////////////////////////////////////////////////////////////////////

#include "Calculator.Code.h"

void setup()
{
  // initialize the M5Stack object
  M5.begin();
  
  terminal.clear();

  gpio_set_direction((gpio_num_t)5, GPIO_MODE_INPUT);
  gpio_pullup_en((gpio_num_t)5);
  i2c_keyboard_master_init();

  il2c_initialize();
}

int index1 = 0;

void loop()
{
#if 1
    Calculator_PolishNotation_Main();
#else
    auto ch = i2c_keyboard_read();
    if (ch != 0)
    {
        //terminal.drawChar(ch);
        //M5.Lcd.drawChar(ch, 0, 0, 2);
        M5.Lcd.printf("[%d] 0x%02x    ", index1++, ch);
    }
    else
    {
        delay(100);
        M5.update();
    }
    /*
    auto ch = i2c_keyboard_read();
    M5.Lcd.printf("[%d] 0x%02x    ", index1++, ch);
    delay(1000);
    M5.update();
    */
#endif
}
