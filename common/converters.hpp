#pragma once

#include "intTypes.hpp"
#include <utility>

/// @brief Converte um valor u4 para um valor em int32_t
/// @param value valor u4
/// @return valor int32_t
int32_t u4ToInt (u4 value);

/// @brief Converte um valor u4 para um valor em int64_t
/// @param low bytes menos significativos do valor u4
/// @param high bytes mais significativos do valor u4
/// @return valor int64_t
int64_t u4ToLong (u4 low, u4 high);

/// @brief Converte um valor u4 para um valor em float
/// @param value valor u4
/// @return valor float
float u4ToFloat (u4 value);

/// @brief Converte um valor u4 para um valor em double
/// @param low bytes menos significativos do valor u4
/// @param high bytes mais significativos do valor u4
/// @return valor double
double u4ToDouble(u4 low, u4 high);


/// @brief Converte um valor int32_t para um valor u4
/// @param value valor int32_t
/// @return valor u4
u4 intToU4(int32_t value);

/// @brief Converte um valor int64_t para um par de u4
/// @param value valor int64_t
/// @return retorna um par de valores u4, na ordem {low, high}
std::pair<u4, u4> longToU8(int64_t value);

/// @brief Converte um valor float para um valor u4
/// @param value valor float
/// @return valor u4
u4 floatToU4(float value);

/// @brief Converte um valor double para um par de u4
/// @param value valor double
/// @return retorna um par de valores u4, na ordem {low, high}
std::pair<u4,u4> doubleToU8(double value);

