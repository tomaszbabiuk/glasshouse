/*
  Relay.h - Library for controlling a relay on specific port
*/
#ifndef Relay_h
#define Relay_h

#include <Arduino.h>

class Relay
{
  public:
    Relay(int pin);
    void on();
    void off();
    bool isOn();
  private:
    int _pin;
    bool _state;
};

#endif
