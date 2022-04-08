/*
  Relay.cpp - Library for controlling a relay on specific port
*/

#include <Arduino.h>
#include "Relay.h"

Relay::Relay(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  off();
}

void Relay::on() {
  _state = true;
  digitalWrite(_pin, HIGH);
}

void Relay::off() {
  _state = false;
  digitalWrite(_pin, LOW);
}

bool Relay::isOn() {
  return _state;
}
