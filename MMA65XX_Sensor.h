#ifndef __MMA65XX_H__
#define __MMA65XX_H__

#include <Adafruit_Sensor.h>
#include <stdint.h>

class MMA65XX_Sensor {

 public:
  typedef uint16_t Msg;
 
  MMA65XX_Sensor(int _ss_pin);
  bool begin();
  bool getEvent(sensors_event_t* evt);

 private:
  Msg transfer(Msg data);
  bool ensureResponse(Msg msg, bool x_axis); //is the data returned valid?
  double getAccelData(Msg msg);
  void printBin(Msg num);

  sensors_event_t cur_event;
  int ss_pin;
  
};

#endif
