#pragma once

#include <stdint.h>

class Rx5808 {
 public:
  Rx5808(uint8_t selPin);
  void init();
  void setFrequency(uint16_t freq);

 private:
  uint8_t m_selPin;    // CS (CH2)
};