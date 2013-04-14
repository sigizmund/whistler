#ifndef __ACTIVITY_SENDER_H
#define __ACTIVITY_SENDER_H

#include <RF24.h>
#include <arpix.h>
#include "pir.h"

class RadioSendingMotionCallback : public MotionDetectionCallback {

private:
  RF24* radio_;
public:
  // Creates a callback object, which will relay the status using
  // RF24 radio link to the server.
  RadioSendingMotionCallback(unsigned short ce_pin, unsigned short csn_pin);

  // Initialises the radio. Must be called prior to using this callback
  void init();

  // Virtual dtor. Realistically will never be called on Arduino
  virtual ~RadioSendingMotionCallback();

  // Callback which will be called every time some motion is
  // detected by the PirSensor object.
  virtual void OnMotionDetected(unsigned short detected_for_ms);
protected:
  // Calculates parity bit for a given number.
  unsigned char parity(unsigned long ino);
};

#endif