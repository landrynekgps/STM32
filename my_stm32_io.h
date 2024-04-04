#ifndef MY_STM32_IO_H
#define MY_STM32_IO_H

#include "esphome.h"

class MySTM32IO : public Component, public Switch {
public:
  uint8_t address;
  uint8_t output_data;
  uint8_t input_data;

  MySTM32IO(uint8_t addr);

  void setup() override;
  void write_state(bool state) override;
  bool read_state() override;
  void set_address(uint8_t addr);
};

#endif
