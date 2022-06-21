#ifndef MILLIS_DELAY
#define MILLIS_DELAY
#include <Arduino.h>
class MillisDelay {
 private:
  bool finishNow;
  unsigned long msDelay;
  bool running;
  unsigned long startTime;

  public:
    MillisDelay();
    void start(unsigned long delay);
    void stop();
    bool justFinished();
    void repeat();
};
#endif