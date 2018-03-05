#include "microbit_Screen.h"
#include "Wire.h"
#include "MMA8653.h"

#include <il2c.h>
 
//////////////////////////////////////////////////////////

#include "Accelometer.Code.h"

//////////////////////////////////////////////////////////

MMA8653 accelometer;

void setup()
{
  il2c_initialize();
}

void loop()
{
  Accelometer_Demo_Main();
}

