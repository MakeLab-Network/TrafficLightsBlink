#include <Arduino.h>
#include "SwitchingAction.h"

SwitchingAction::SwitchingAction(uint8_t pin1, uint8_t pin2, bool highIsOn)
{
  _on = highIsOn ? HIGH : LOW;
  _off = highIsOn ? LOW : HIGH;
  _pin[0] = pin1;
  _pin[1] = pin2;
  for (int i = 0; i < 2; i++) {
    pinMode(_pin[i], OUTPUT);
    digitalWrite(_pin[i], _off);
  }
}

void SwitchingAction::start()
{
  _nextPinIdx = 0;
  run();
}

void SwitchingAction::run()
{
  digitalWrite(_pin[_nextPinIdx], _on);
  _nextPinIdx = (_nextPinIdx + 1) % 2;
  digitalWrite(_pin[_nextPinIdx], _off);
}

void SwitchingAction::stop()
{
  digitalWrite(_pin[0], _off);
  digitalWrite(_pin[1], _off);
}
