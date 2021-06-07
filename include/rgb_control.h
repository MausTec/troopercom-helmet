#ifndef __rgb_control_h
#define __rgb_control_h

#include "board.h"
#include "color.h"

void rgb_control_set_color(rgb_channel_t channel, rgb_color_t color);
void rgb_control_fade_color(rgb_channel_t channel, rgb_color_t color, int fade_time);

#endif