#include <stdio.h>
#include "myGPTimer.h"
#include "driver/gptimer.h"
#include "esp_rom_sys.h"

gptimer_handle_t gptimer = NULL;

//__________________________________________________________________________________________________


void myTimer_setup(void)
{
    gptimer_config_t timer_config = {
    .clk_src = GPTIMER_CLK_SRC_DEFAULT, // Select the default clock source
    .direction = GPTIMER_COUNT_UP,      // Counting direction is up
    .resolution_hz = 1 * 1000 * 1000,   // Resolution is 1 MHz, i.e., 1 tick equals 1 microsecond
    };

        
    gptimer_new_timer(&timer_config, &gptimer);                 // Create a timer instance    
    myTimer_setup_alarm();
    gptimer_enable(gptimer);            // Enable the timer
    gptimer_start(gptimer);             // Start the timer

}
//______________________________________________________________________________________


static bool alarm_cb(gptimer_handle_t timer, const gptimer_alarm_event_data_t *edata, void *user_ctx)
{

    //gpio_set_level(TRIG, 1);
    esp_rom_delay_us(10);
    //gpio_set_level(TRIG,0);

    return false;

}


void myTimer_setup_alarm(void)
{
    gptimer_alarm_config_t alarm_config = {
    .reload_count = 0,      // When the alarm event occurs, the timer will automatically reload to 0
    .alarm_count = 100000, // 1000ms
    .flags.auto_reload_on_alarm = true, // Enable auto-reload function  
    };

    gptimer_set_alarm_action(gptimer, &alarm_config);           // Set the timer's alarm action
 
    gptimer_event_callbacks_t cbs = {
        .on_alarm = alarm_cb,                                   // Call the user callback function when the alarm event occurs
    };   
    gptimer_register_event_callbacks(gptimer, &cbs, NULL);


}
