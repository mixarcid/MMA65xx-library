# MMA65xx Sensor Driver

An implimentation of the Adafruit Unified Sensor Driver for interfacing with MMA65xx accelerometers (https://github.com/adafruit/Adafruit_Sensor). It currently only gives correct data for the MMA6525KW MMA6525KWR2 sensors, but support will come soon for all the sensors in the series.

```c++
#include <MMA65XX_Sensor.h>

int main() {
  Serial.begin(9600);
  MMA65XX_Sensor sensor(SS_PIN);
  while(true) {
    sensors_event_t evt;
    sensor.getEvent(&evt);
    Serial.print("X acceleration: ");
    Serial.println(evt.acceleration.x);
    Serial.print("Y acceleration: ");
    Serial.println(evt.acceleration.y);
    Serial.println("");
    delay(100);
  }
}
```
