#ifndef __color_h
#define __color_h

#include "freertos/FreeRTOS.h"

#define RGB_RED { .r = 255, .g = 0, .b = 0 }

typedef struct hsv_color {
    double h;
    double s;
    double v;
} hsv_color_t;

typedef struct rgb_color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_color_t;

hsv_color_t rgb2hsv(rgb_color_t in);
rgb_color_t hsv2rgb(hsv_color_t in);
rgb_color_t hueshift(rgb_color_t in, double hue);
rgb_color_t rgb(uint8_t r, uint8_t g, uint8_t b);
rgb_color_t hsv(double h, double s, double v);

#endif