//
//    FILE: MS5611_test_plotter.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo application
//    DATE: 2022-01-15
//     URL: https://github.com/RobTillaart/MS5611


#include "MS5611.h"

MS5611 MS5611(0x76);

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println();
  if (MS5611.begin() == true)
  {
    Serial.println("MS5611 found.");
  }
  else
  {
    Serial.println("MS5611 not found. halt.");
    while (1)
    {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN, LOW);
      delay(1000);
    }
  }
  Serial.println("TEMP\tPRESSURE");

  MS5611.setOversampling(OSR_ULTRA_HIGH);

}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  MS5611.read();
  Serial.print(MS5611.getTemperature(), 4);
  Serial.print("\t");
  Serial.print(MS5611.getPressure(), 4);
  Serial.println();
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
}
