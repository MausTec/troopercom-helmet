#include "rgb_control.h"

void rgb_control_set_color(rgb_channel_t channel, rgb_color_t color) {
    rgb_channel_config_t config = get_rgb_channel(channel);
    ledc_set_duty(config.mode, config.channel_r, color.r);
    ledc_set_duty(config.mode, config.channel_g, color.g);
    ledc_set_duty(config.mode, config.channel_b, color.b);
    ledc_update_duty(config.mode, config.channel_r);
    ledc_update_duty(config.mode, config.channel_g);
    ledc_update_duty(config.mode, config.channel_b);
}

void rgb_control_fade_color(rgb_channel_t channel, rgb_color_t color, int fade_time) {
    rgb_channel_config_t config = get_rgb_channel(channel);
    ledc_set_fade_with_time(config.mode, config.channel_r, color.r, fade_time);
    ledc_set_fade_with_time(config.mode, config.channel_g, color.g, fade_time);
    ledc_set_fade_with_time(config.mode, config.channel_b, color.b, fade_time);
    ledc_fade_start(config.mode, config.channel_r, LEDC_FADE_NO_WAIT);
    ledc_fade_start(config.mode, config.channel_g, LEDC_FADE_NO_WAIT);
    ledc_fade_start(config.mode, config.channel_b, LEDC_FADE_NO_WAIT);
}