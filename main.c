#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BUZZER_GPIO GPIO_NUM_4  // Choisis le bon GPIO ici

void app_main(void) {
    // Configure le GPIO en sortie
    gpio_reset_pin(BUZZER_GPIO);
    gpio_set_direction(BUZZER_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        // Allumer le buzzer
        gpio_set_level(BUZZER_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(800));  // 0.5 sec
        printf("souber \n");

        // Éteindre le buzzer
        gpio_set_level(BUZZER_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(800));  // 0.5 sec
    }
}
