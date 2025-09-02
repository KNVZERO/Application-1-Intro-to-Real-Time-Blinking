/* --------------------------------------------------------------
   Application: 01 - Rev1
   Name: Kelvin Vu
   Release Type: Baseline Multitask Skeleton Starter Code 
   Class: Real Time Systems - Su 2025
   AI Use: Commented inline
---------------------------------------------------------------*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_0  // Using GPIO2 for the LED

// Task to blink an LED at 2 Hz (500 ms period: 250 ms ON, 250 ms OFF)
void status_blink(void *pvParameters) {
    bool led_on = false;
    TickType_t currentTime = pdTICKS_TO_MS( xTaskGetTickCount() );
    
    while (1) {
      currentTime = pdTICKS_TO_MS( xTaskGetTickCount() );
        // TODO: Set LED pin high or low based on led_on flag; right now it's always on... boring; hint in the commented out print statement
        gpio_set_level(LED_PIN, led_on); // set LED state to bool led_on
        led_on = !led_on;  // toggle state for next time
        printf("Status LED %s @ %lu \n", led_on ? "ON" : "OFF", currentTime);
        // Optional: printf("LED %s\n", led_on ? "ON" : "OFF");
        
        vTaskDelay(pdMS_TO_TICKS(250)); // Delay for 250 ms using MS to Ticks Function vs alternative which is MS / ticks per ms
        //vTaskDelay(pdMS_TO_TICKS(50));
        
        
    }
    vTaskDelete(NULL); // We'll never get here; tasks run forever
}

// Task to print a message every 10000 ms (10 seconds)
void print_status(void *pvParameters) {
    while (1) {
        // TODO: Print a periodic message based on thematic area. Could be a counter or timestamp.
        // printf("This boring real-time system is alive!\n");       
        printf("Signal received @: %lu ms\n", (unsigned long)(xTaskGetTickCount()*portTICK_PERIOD_MS));
        vTaskDelay(pdMS_TO_TICKS(10000)); // Delay for 10000 ms
    }
    vTaskDelete(NULL); // We'll never get here; tasks run forever
}

void app_main() {
    // Initialize LED GPIO     
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    
    // Instantiate/ Create tasks: 
    // . pointer to task function, 
    // . descriptive name, [has a max length; located in the FREERTOS_CONFIG.H]
    // . stack depth, 
    // . parameters [optional] = NULL 
    // . priority [0 = low], 
    // . pointer referencing this created task [optional] = NULL
    // Learn more here https://www.freertos.org/Documentation/02-Kernel/04-API-references/01-Task-creation/01-xTaskCreate
    xTaskCreate(status_blink, "Status Beacon", 2048, NULL, 1, NULL);
    xTaskCreate(print_status, "System Status", 2048, NULL, 1, NULL);

}