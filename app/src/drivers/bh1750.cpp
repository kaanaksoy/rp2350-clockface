/*
 * bh1750.cpp
 *
 * This class is responsible for the BH1750 light sensor.
 * Author: Kaan Aksoy
 */

#include "bh1750.hpp"

BH1750::BH1750(uint8_t addr) : _addr(addr) {}

BH1750::~BH1750() {}

void BH1750::init(mode m) {}

float BH1750::readLightLevel(void) { return 0.0f; }
