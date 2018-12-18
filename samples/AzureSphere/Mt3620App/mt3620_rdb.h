/// This header contains the peripheral pinout definitions for the
/// MT3620 Reference Development Board (RDB)
#pragma once

#include <soc/mt3620_gpios.h>
#include <soc/mt3620_uarts.h>

/// <summary>LED 1 Red channel is GPIO8.</summary>
#define MT3620_RDB_LED1_RED MT3620_GPIO8

/// <summary>LED 1 Green channel is GPIO9.</summary>
#define MT3620_RDB_LED1_GREEN MT3620_GPIO9

/// <summary>LED 1 Blue channel is GPIO10.</summary>
#define MT3620_RDB_LED1_BLUE MT3620_GPIO10

/// <summary>LED 2 Red channel is GPIO15.</summary>
#define MT3620_RDB_LED2_RED MT3620_GPIO15

/// <summary>LED 2 Green channel is GPIO16.</summary>
#define MT3620_RDB_LED2_GREEN MT3620_GPIO16

/// <summary>LED 2 Blue channel is GPIO17.</summary>
#define MT3620_RDB_LED2_BLUE MT3620_GPIO17

/// <summary>LED 3 Red channel is GPIO18.</summary>
#define MT3620_RDB_LED3_RED MT3620_GPIO18

/// <summary>LED 3 Green channel is GPIO19.</summary>
#define MT3620_RDB_LED3_GREEN MT3620_GPIO19

/// <summary>LED 3 Blue channel is GPIO20.</summary>
#define MT3620_RDB_LED3_BLUE MT3620_GPIO20

/// <summary>LED 4 Red channel is GPIO21.</summary>
#define MT3620_RDB_LED4_RED MT3620_GPIO21

/// <summary>LED 4 Green channel is GPIO22.</summary>
#define MT3620_RDB_LED4_GREEN MT3620_GPIO22

/// <summary>LED 4 Blue channel is GPIO23.</summary>
#define MT3620_RDB_LED4_BLUE MT3620_GPIO23

/// <summary>Status LED Red channel is GPIO45.</summary>
#define MT3620_RDB_STATUS_LED_RED MT3620_GPIO45

/// <summary>Status LED Green channel is GPIO46.</summary>
#define MT3620_RDB_STATUS_LED_GREEN MT3620_GPIO46

/// <summary>Status LED Blue channel is GPIO47.</summary>
#define MT3620_RDB_STATUS_LED_BLUE MT3620_GPIO47

/// <summary>Networking LED Red channel is GPIO48.</summary>
#define MT3620_RDB_NETWORKING_LED_RED MT3620_GPIO48

/// <summary>Networking LED Green channel is GPIO14.</summary>
#define MT3620_RDB_NETWORKING_LED_GREEN MT3620_GPIO14

/// <summary>Networking LED Blue channel is GPIO11.</summary>
#define MT3620_RDB_NETWORKING_LED_BLUE MT3620_GPIO11

/// <summary>Button A is GPIO12.</summary>
#define MT3620_RDB_BUTTON_A MT3620_GPIO12

/// <summary>Button B is GPIO13.</summary>
#define MT3620_RDB_BUTTON_B MT3620_GPIO13

// Header 1, pin 1 is SYS_RST
// Header 1, pin 2 is GND

/// <summary>GPIO59 is exposed on header 1, pin 3</summary>
#define MT3620_RDB_HEADER1_PIN3_GPIO MT3620_GPIO59

/// <summary>GPIO0 is exposed on header 1, pin 4</summary>
#define MT3620_RDB_HEADER1_PIN4_GPIO MT3620_GPIO0

/// <summary>GPIO56 is exposed on header 1, pin 5</summary>
#define MT3620_RDB_HEADER1_PIN5_GPIO MT3620_GPIO56

/// <summary>GPIO1 is exposed on header 1, pin 6</summary>
#define MT3620_RDB_HEADER1_PIN6_GPIO MT3620_GPIO1

/// <summary>GPIO58 is exposed on header 1, pin 7</summary>
#define MT3620_RDB_HEADER1_PIN7_GPIO MT3620_GPIO58

/// <summary>GPIO2 is exposed on header 1, pin 8</summary>
#define MT3620_RDB_HEADER1_PIN8_GPIO MT3620_GPIO2

/// <summary>GPIO57 is exposed on header 1, pin 9</summary>
#define MT3620_RDB_HEADER1_PIN9_GPIO MT3620_GPIO57

/// <summary>GPIO3 is exposed on header 1, pin 10</summary>
#define MT3620_RDB_HEADER1_PIN10_GPIO MT3620_GPIO3

/// <summary>GPIO60 is exposed on header 1, pin 11</summary>
#define MT3620_RDB_HEADER1_PIN11_GPIO MT3620_GPIO60

/// <summary>GPIO4 is exposed on header 1, pin 12</summary>
#define MT3620_RDB_HEADER1_PIN12_GPIO MT3620_GPIO4

// Header 2, pins 1, 3, 5, 7 are only supported as the ISU0 UART
#define MT3620_RDB_HEADER2_ISU0_UART MT3620_UART_ISU0

// Header 2, pin 2 is GND

/// <summary>GPIO5 is exposed on header 2, pin 4</summary>
#define MT3620_RDB_HEADER2_PIN4_GPIO MT3620_GPIO5

/// <summary>GPIO6 is exposed on header 2, pin 6</summary>
#define MT3620_RDB_HEADER2_PIN6_GPIO MT3620_GPIO6

/// <summary>GPIO7 is exposed on header 2, pin 8</summary>
#define MT3620_RDB_HEADER2_PIN8_GPIO MT3620_GPIO7

/// <summary>GPIO30 is exposed on header 2, pin 9</summary>
#define MT3620_RDB_HEADER2_PIN9_GPIO MT3620_GPIO30

// Header 2, pin 10 is ADC VREF

/// <summary>GPIO41 is exposed on header 2, pin 11</summary>
#define MT3620_RDB_HEADER2_PIN11_GPIO MT3620_GPIO41

/// <summary>GPIO43 is exposed on header 2, pin 12</summary>
#define MT3620_RDB_HEADER2_PIN12_GPIO MT3620_GPIO43

/// <summary>GPIO42 is exposed on header 2, pin 13</summary>
#define MT3620_RDB_HEADER2_PIN13_GPIO MT3620_GPIO42

/// <summary>GPIO44 is exposed on header 2, pin 14</summary>
#define MT3620_RDB_HEADER2_PIN14_GPIO MT3620_GPIO44

// Header 3, pin 1 is 5V
// Header 3, pin 2 is GND
// Header 3, pin 3 is 3V3
// Header 3, pin 4 is RTC_WAKEUP

// Header 3, pin 6 is IO0 UART TX
// Header 3, pin 8 is IO1 UART TX
// Header 3, pin 10 is PMU EN

// Header 3, pins 5, 7, 9, 11 are only supported as the ISU3 UART
#define MT3620_RDB_HEADER3_ISU3_UART MT3620_UART_ISU3

/// <summary>GPIO70 is exposed on header 3, pin 12</summary>
#define MT3620_RDB_HEADER3_PIN12_GPIO MT3620_GPIO70

// Header 4, pin 1 is SWDIO
// Header 4, pin 2 is GND
// Header 4, pin 3 is SWCLK
// Header 4, pin 4 is SWO

// Header 4, pins 5, 7, 9, 11 are only supported as the ISU1 UART
#define MT3620_RDB_HEADER4_ISU1_UART MT3620_UART_ISU1

// Header 4, pins 6, 8, 10, 12 are only supported as the ISU2 UART
#define MT3620_RDB_HEADER4_ISU2_UART MT3620_UART_ISU2

/// <summary>GPIO35 is exposed on header 4, pin 13</summary>
#define MT3620_RDB_HEADER4_PIN13_GPIO MT3620_GPIO35

/// <summary>GPIO40 is exposed on header 4, pin 14</summary>
#define MT3620_RDB_HEADER4_PIN14_GPIO MT3620_GPIO40
