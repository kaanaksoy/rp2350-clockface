#ifndef __BH1750_H__
#define __BH1750_H__

#define BH1750_DEVICE_ADDR 0x23
#define BH1750_CONVERSION_FACTOR 1.2f

#define BH1750_POWER_DOWN 0x00
#define BH1750_POWER_ON 0x01
#define BH1750_RESET 0x07

#define BH1750_DEFAULT_MTREG 69
#define BH1750_MTREG_MIN 31
#define BH1750_MTREG_MAX 254

extern "C" {
#include "bsp_i2c.h"
}

enum mode {
  // same as Power Down
  UNCONFIGURED = 0,
  // Measurement at 1 lux resolution. Measurement time is approx 120ms.
  CONTINUOUS_HIGH_RES_MODE = 0x10,
  // Measurement at 0.5 lux resolution. Measurement time is approx 120ms.
  CONTINUOUS_HIGH_RES_MODE_2 = 0x11,
  // Measurement at 4 lux resolution. Measurement time is approx 16ms.
  CONTINUOUS_LOW_RES_MODE = 0x13,
  // Measurement at 1 lux resolution. Measurement time is approx 120ms.
  ONE_TIME_HIGH_RES_MODE = 0x20,
  // Measurement at 0.5 lux resolution. Measurement time is approx 120ms.
  ONE_TIME_HIGH_RES_MODE_2 = 0x21,
  // Measurement at 4 lux resolution. Measurement time is approx 16ms.
  ONE_TIME_LOW_RES_MODE = 0x23
};

class BH1750 {

public:
  BH1750(uint8_t addr = BH1750_DEVICE_ADDR);
  virtual ~BH1750();

  void init(mode m = CONTINUOUS_HIGH_RES_MODE);
  float readLightLevel(void);

private:
  uint8_t _addr;
  mode _mode;
  uint8_t _mtreg;
};

#endif
