#include "converters.hpp"
#include <math.h>
#include <cstring>

#pragma region u4ToType


int32_t u4ToInt (u4 value) {
  return (int32_t) value;
}

int64_t u4ToLong (u4 low, u4 high) {
  return ((int64_t) high << 32) | (int64_t) low;
}

float u4ToFloat (u4 value) {
    int sinal = ((value >> 31) == 0) ? 1 : -1;
    int expon = ((value >> 23) & 0xff);
    int mant = (expon == 0) ? (value & 0x7fffff) << 1 : (value & 0x7fffff) | 0x800000;
    float result = (sinal) * (mant) * (pow(2, expon - 150));
    return result;
}

double u4ToDouble(u4 low, u4 high) {
    uint64_t valor = ((uint64_t)high << 32) | (uint64_t)low;
    // int sinal = ((valor >> 63) == 0) ? 1 : -1;
    // int expon = ((valor >> 52) & 0x7ffL);
    // long mant = (expon == 0) ? ((valor & 0xfffffffffffffL) << 1) : ((valor & 0xfffffffffffffL) | 0x10000000000000L);

    // double retorno = sinal * mant * (pow(2, expon - 1075));
    // return retorno;

    double d;
    memcpy(&d, &valor, sizeof(d));
    return d;
}

#pragma endregion

#pragma region typeToU4

u4 intToU4(int32_t value) {
  return (u4) value;
}

std::pair<u4, u4> longToU8(int64_t value) {
  u4 low = (u4) value;
  u4 high = (u4) (value >> 32);

  return {low, high};
}

u4 floatToU4(float value) {
  u4 result = 0;
  int sinal = (value < 0) ? 1 : 0;
  int expoente = 0;
  float mantissa = 0;

  if (value == 0) {
    return 0;
  }

  if (value == INFINITY) {
    return 0x7f800000;
  }

  if (value == -INFINITY) {
    return 0xff800000;
  }

  if (isnan(value)) {
    return 0x7fc00000;
  }

  if (value < 0) {
    value = -value;
  }

  mantissa = frexp(value, &expoente);

  expoente += 126;
  mantissa *= 2;
  if (mantissa >= 1) {
    mantissa -= 1;
  }

  result = (sinal << 31) | (expoente << 23) | ((int) (mantissa * pow(2, 23)));

  return result;
}

std::pair<u4,u4> doubleToU8(double value) {

  int sinal = (value < 0) ? 1 : 0;
  int expoente = 0;
  double mantissa = 0;

  if (value == 0) {
    return {0, 0};
  }

  if (value == INFINITY) {
    return {0, 0x7ff00000}; // 0x7ff0000000000000
  }

  if (value == -INFINITY) {
    return {0, 0xfff00000}; // 0xfff0000000000000
  }

  if (isnan(value)) {
    return {0, 0x7ff80000}; // 0x7ff8000000000000
  }

  if (value < 0) {
    value = -value;
  }

  mantissa = frexp(value, &expoente);

  expoente += 1022;
  mantissa *= 2;
  if (mantissa >= 1) {
    mantissa -= 1;
  }

  u8 result = ((u8) sinal << 63) | ((u8) expoente << 52) | ((u8) (mantissa * pow(2, 52)));

  u4 low = result & 0xffffffff;
  u4 high = result >> 32;
  return {low, high};
}

#pragma endregion