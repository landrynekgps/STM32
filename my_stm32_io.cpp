#include "my_stm32_io.h"

MySTM32IO::MySTM32IO(uint8_t addr) : address(addr) {}

void MySTM32IO::setup() {
  Wire.begin();
  Wire.setClock(100000);
}

void MySTM32IO::write_state(bool state) {
  output_data = state ? 0x01 : 0x00;
  Wire.beginTransmission(static_cast<uint8_t>(address));
  Wire.write(output_data);
  Wire.endTransmission();
}

bool MySTM32IO::read_state() {
  Wire.requestFrom(static_cast<uint8_t>(address), static_cast<uint8_t>(1));
  if (Wire.available()) {
    input_data = Wire.read();
    return input_data == 0x01;
  }
  return false;
}

void MySTM32IO::set_address(uint8_t addr) {
  address = addr;
}
