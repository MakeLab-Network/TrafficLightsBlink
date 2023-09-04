#ifndef SwitchingAction_h
#define SwitchingAction_h

#include <Arduino.h>
#include <Periodic.h>

class SwitchingAction : public PeriodicAction {
  public:
    SwitchingAction(uint8_t pin1, uint8_t pin2, bool highIsOn = true);
    void start();
    void run();
    void stop();
  private:
    uint8_t _pin[2];
    size_t _nextPinIdx;
    uint8_t _on;
    uint8_t _off;
};

#endif // SwitchingAction_h
