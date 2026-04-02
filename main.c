
// FEITO POR ANDREY


#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BOTAO_PIN  21

void app_main(void) {
    int semaforo = 0;   // Estado do semáforo
    static int trf = 0;        // Variável de co

    gpio_reset_pin(BOTAO_PIN);
    gpio_set_direction(BOTAO_PIN, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BOTAO_PIN, GPIO_PULLDOWN_ONLY);

    printf("'trf'...\n");

    while (1) {
        int botao = gpio_get_level(BOTAO_PIN);

        
        if (botao == 1 && semaforo == 0) {
            trf = 1; 
        } 
        else if(botao == 0 && semaforo == 0 && trf == 1){
              trf = 1;
        }
        else if (botao == 1 && semaforo != 0) {
            trf = 0; 
        }
        else if (botao == 0 && semaforo == 0) {
            trf = 0; 
        }
        else {
            trf = trf; 
        }


        printf("Semaforo: %d | Botao: %d | trf: %d\n", semaforo, botao, trf);

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
