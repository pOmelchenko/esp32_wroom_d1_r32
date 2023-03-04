#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "hal/gpio_types.h"

_Noreturn void app_main(void)
{
    gpio_config_t gpioConfig = {
            .intr_type = GPIO_INTR_DISABLE,
            .mode = GPIO_MODE_OUTPUT,
            .pin_bit_mask = (1ULL << GPIO_NUM_2)
    };

    gpio_config(&gpioConfig);

    bool enable = false;
    while (true)
    {
        gpio_set_level(GPIO_NUM_2, enable = !enable);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
