#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#define LED1 7
#define LED2 8

void Task1(void *pvParameters) {
  pinMode(LED1, OUTPUT);

  while (1) {
    digitalWrite(LED1, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(LED1, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void Task2(void *pvParameters) {
  pinMode(LED2, OUTPUT);

  while (1) {
    digitalWrite(LED2, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(LED2, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup() {
  xTaskCreate(Task1, "LED1", 128, NULL, 1, NULL);
  xTaskCreate(Task2, "LED2", 128, NULL, 2, NULL);
}

void loop() {}