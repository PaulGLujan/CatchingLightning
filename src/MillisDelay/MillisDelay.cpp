

// MillisDelay.cpp

/*
 * (c)2018 Forward Computing and Control Pty. Ltd.
 * NSW Australia, www.forward.com.au
 * This code is not warranted to be fit for any purpose. You may only use it at
 * your own risk. This generated code may be freely used for both private and
 * commercial use provided this copyright is maintained.
 */

// include Arduino.h for millis()
#include "MillisDelay.h"

#include <Arduino.h>

MillisDelay::MillisDelay() {
  finishNow = false;
  running = false;
  startTime = 0;
}

/**
   Start a delay of this many milliseconds
   @param delay in millisconds, 0 means justFinished() will return true on first
   call
*/
void MillisDelay::start(unsigned long delay) {
  finishNow = false;
  msDelay = delay;
  running = true;
  startTime = millis();
}

/**
   Stop the delay
   justFinished() will now never return true
   until after start(),restart() or repeat() called again
*/
void MillisDelay::stop() {
  running = false;
  finishNow = false;  // do not finish early
}

/**
  Has the delay ended/expired or has finish() been called?
  justFinished() returns true just once when delay first exceeded or the first
  time it is called after finish() called
*/
bool MillisDelay::justFinished() {
  if (running && (finishNow || (millis() - startTime) >= msDelay)) {
    stop();
    return true;
  }
  return false;
}

/**
   repeat()
   Do same delay again but allow for a possible delay in calling justFinished()
*/
void MillisDelay::repeat() {
  startTime = startTime + msDelay;
  running = true;
  finishNow = false;  // do not finish early
}