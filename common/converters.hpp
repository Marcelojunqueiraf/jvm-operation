#pragma once

#include "intTypes.hpp"
#include <utility>

int32_t u4ToInt (u4 value);
int64_t u4ToLong (u4 low, u4 high);
float u4ToFloat (u4 value);
double u4ToDouble(u4 low, u4 high);

u4 intToU4(int32_t value);
std::pair<u4, u4> longToU8(int64_t value);
u4 floatToU4(float value);
std::pair<u4,u4> doubleToU8(double value);
