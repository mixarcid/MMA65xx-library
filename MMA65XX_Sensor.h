#ifndef __MMA65XX_H__
#define __MMA65XX_H__

#include <Adafruit_Sensor.h>
#include <stdint.h>

class MMA65XX_Sensor {

 public:
  typedef uint16_t Msg;
 
  MMA65XX_Sensor(int _ss_pin);
  bool getEvent(sensors_event_t* evt);

 private:
  Msg transfer(Msg data);
  double getAccelData(Msg msg);
  void printBin(Msg num);
  
  int ss_pin;
  
};

#endif
