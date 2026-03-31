#include <stdio.h>
#include "myJoyStick.h"
#include "driver/gpio.h"
#include "esp_adc/adc_oneshot.h"


int BUTTONPIN;
int CHANNELX;
int CHANNELY;
adc_oneshot_unit_handle_t adc1_handle;

adc_oneshot_unit_init_cfg_t adc_config = {
    .unit_id = ADC_UNIT_1,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
};

adc_oneshot_chan_cfg_t default_channel_config = {
    .bitwidth = ADC_BITWIDTH_DEFAULT,           //dit is de max supported width en dat is 13
    .atten = ADC_ATTEN_DB_12,       //=> hierdoor is het bereik 3v3
};





void myJoyStick_Setup(int pinX, int pinY, int pinClick)
{
    BUTTONPIN = pinClick;
    CHANNELX = pinX;
    CHANNELY = pinY;
    gpio_reset_pin(pinClick);
    gpio_set_direction(pinClick, GPIO_MODE_INPUT);
    gpio_pullup_en(pinClick);

    adc_oneshot_new_unit(&adc_config, &adc1_handle);
    adc_oneshot_config_channel(adc1_handle, pinX, &default_channel_config);
    adc_oneshot_config_channel(adc1_handle, pinY, &default_channel_config);


}

myJoyStick_t myJoyStick_Read(void)
{
    myJoyStick_t jefke;
    adc_oneshot_read(adc1_handle, CHANNELX , &jefke.X_value);
    adc_oneshot_read(adc1_handle, CHANNELY, &jefke.Y_value);
    
    return jefke;
}

int myJoyStick_ReadButton(void)
{

    return gpio_get_level(BUTTONPIN);

}



