RGB_MATRIX_EFFECT(layer_rgb)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool layer_rgb(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV hsv_green = rgb_matrix_config.hsv; hsv_green.h = 85, hsv_green.s = 255;
    //HSV hsv_red = rgb_matrix_config.hsv; hsv_red.h = 0, hsv_red.s = 255;
    HSV hsv_blue = rgb_matrix_config.hsv; hsv_blue.h = 152, hsv_blue.s = 255;
    HSV hsv_yellow = rgb_matrix_config.hsv; hsv_yellow.h = 45, hsv_yellow.s = 255;
    HSV hsv_black = rgb_matrix_config.hsv; hsv_black.h = 0, hsv_black.s = 0; hsv_black.v = 0;



    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index <= led_max && index != NO_LED) {

                HSV outputColor = rgb_matrix_config.hsv;


                for(uint8_t i = layer; i>=0; i--) {


                    if(layer_state_is(i) || i == 0) {
                        if(keymap_key_to_keycode(i, (keypos_t){col,row}) == KC_NO) {
                            outputColor = hsv_black;
                            break;

                        } else if (keymap_key_to_keycode(i, (keypos_t){col,row}) > KC_TRNS) {
                            switch (i) {

                                case 0:
                                    outputColor = hsv_black;
                                    break;

                                case 1:
                                    outputColor = hsv_green;
                                    break;

                                case 2:
                                    outputColor = hsv_blue;
                                    break;

                                case 3:
                                    outputColor = hsv_yellow;
                                    break;

                                default:
                                    outputColor = hsv_black;
                                    break;
                            }
                            break;
                        }
                    }
                }


                rgb_matrix_set_color(index, rgb_matrix_hsv_to_rgb(outputColor).r, rgb_matrix_hsv_to_rgb(outputColor).g, rgb_matrix_hsv_to_rgb(outputColor).b);

            }
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
