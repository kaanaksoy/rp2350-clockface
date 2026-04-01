# RP2350 Clockface

Firmware for the [Waveshare RP2350-Touch-LCD-2.8C](https://www.waveshare.com/wiki/RP2350-Touch-LCD-2.8C) board, displaying a custom clock face with sensor data and system controls.

Built with [LVGL v8.4](https://lvgl.io) on the [Pico SDK](https://github.com/raspberrypi/pico-sdk) (v2.2.0+).

## Features

- Image-based clock face with rotating hands
- Temperature and humidity display (via UART from host)
- QR code screen (swipeable)
- Reboot / shutdown controls for the host Raspberry Pi (via UART)

## Hardware

- **MCU**: RP2350B (dual-core Cortex-M33, 240 MHz)
- **Display**: 480x480 round IPS, RGB interface (ST7701S + PIO)
- **Touch**: Capacitive 5-point (GT911)
- **Onboard**: RTC (PCF85063), IMU (QMI8658), battery sense, buzzer

## Prerequisites

- [Pico SDK](https://github.com/raspberrypi/pico-sdk) v2.2.0+ with `PICO_SDK_PATH` environment variable set
- ARM GCC toolchain (`arm-none-eabi-gcc`)
- CMake 3.13+

## Build

```bash
cd app
mkdir build && cd build
cmake ..
make
```
**Output:** build/src/RP2350Clockface.uf2

### Flash
1. Hold BOOTSEL
2. Connect USB
3. copy RP2350Clockface.uf2 to the mounted drive.

## Attribution
- Project scaffolding based on drjonea/RP2350Touch2-8C-Exp.
- BSP drivers from the Waveshare wiki.
