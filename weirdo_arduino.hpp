#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#undef max
#undef min
#include <Arduino.h>

//******* AUTHOR COMMENT *******
// I know, that's f****** weird, that
// bomberman.ino includes that empty file,
// only to include playground.hpp here, but
// thats the way to not get arduino-like
// compilation errors when you
// want to add std::vector to class.
//*****************************
#include "playground.hpp"