#include <Arduino.h>
#include "Periodic.h"

Periodic::Periodic(PeriodicAction* action, unsigned long period, unsigned long duration)
{
    _action = action;
    _period = period;
    _duration = duration;
    _running = false;
}

void Periodic::start()
{
    _startedAt = millis();
    if (!_running) {
      _running = true;
      _lastRun = _startedAt;
      _action->start();
    }
}

void Periodic::run()
{
    if (_running) {
        unsigned long now = millis();
        if (long(now - _lastRun - _period) >= 0) { // using signed to handle overflow
            _lastRun = now;
            if (long(now - _startedAt - _duration) >= 0) { // same here
              _running = false;
              _action->stop();
            } else {
              _action->run();
            }
        }
    }
}
