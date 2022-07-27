#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"

int lower_temperature (WeatherTable a);

void highest_temperature_peryear (WeatherTable a, int outputs[YEARS]);

void highest_rainfall_month_peryear (WeatherTable a, int outputs[YEARS]);

#endif