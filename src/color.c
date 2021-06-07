#include "color.h"
#include "esp_log.h"
#include <math.h>

static const char *TAG = "COLOR";

hsv_color_t rgb2hsv(rgb_color_t in) {
    hsv_color_t hsv;

    double r = (double)in.r / 255.0;
    double g = (double)in.g / 255.0;
    double b = (double)in.b / 255.0;

    double min_v = fmin(r, fmin(g, b));
    double max_v = fmax(r, fmax(g, b));
    double delta = max_v - min_v;

    // value
    hsv.v = max_v;

    // saturation
    if (max_v == 0) {
        hsv.s = 0;
    } else  {
        hsv.s = delta / max_v;
    }

    // hue
    if (max_v == r) {
        hsv.h = (g - b) / delta;
    } else if (max_v == g) {
        hsv.h = 2.0 + (b - r) / delta;
    } else if (max_v == b) {
        hsv.h = 4.0 + (r - g) / delta;
    }

    hsv.h *= 60; // convert to deg
    if (hsv.h < 0) hsv.h += 360; // make positive again

    return hsv;
}

rgb_color_t hsv2rgb(hsv_color_t in) {
    rgb_color_t rgb;
    double r, g, b, l = in.v * 2;

    if (in.s == 0) {
        rgb.r = l * 255;
        rgb.g = l * 255;
        rgb.b = l * 255;
    } else {
        double c = in.v * in.s;
        double x = c * (1 - fabs(fmod(in.h / 60.0, 2) - 1));
        double m = in.v - c;

        switch ((int) floor(in.h / 60)) {
            case 0:
                r = c; g = x; b = 0;
                break;
            case 1:
                r = x; g = c; b = 0;
                break;
            case 2:
                r = 0; g = c; b = x;
                break;
            case 3:
                r = 0; g = x; b = c;
                break;
            case 4:
                r = x; g = 0;  b = c;
                break;
            case 5:
                r = c; g = 0; b = x;
                break;
            default:
                r = 0; g = 0; b = 0;
        }

        rgb.r = (r + m) * 255.0;
        rgb.g = (g + m) * 255.0;
        rgb.b = (b + m) * 255.0;
    }

    return rgb;
}

rgb_color_t hueshift(rgb_color_t in, double hue) {
    hsv_color_t hsv = rgb2hsv(in);
    hsv.h = fmod(hsv.h + hue, 360);
    rgb_color_t rgb = hsv2rgb(hsv);

    ESP_LOGD(TAG, 
        "hueshift(rgb(%02x, %02x, %02x), %f) -> hsv(%f, %f, %f) -> rgb(%02x, %02x, %02x)",
        in.r, in.g, in.b,
        hue,
        hsv.h, hsv.s, hsv.v,
        rgb.r, rgb.g, rgb.b
    );

    return rgb;
}

rgb_color_t hsv(double h, double s, double v) {
    hsv_color_t hsv = { .h = h, .s = s, .v = v };
    return hsv2rgb(hsv);
}