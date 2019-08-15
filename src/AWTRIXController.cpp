//This is only a test...

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Arduino.h"

TaskHandle_t Loop2;

void loop2( void * parameter);

int a = 0;

void setup(){
  Serial.begin(115200);

  xTaskCreatePinnedToCore(
      loop2,   /* Task function. */
      "Loop2", /* name of task. */
      10000,   /* Stack size of task */
      NULL,    /* parameter of the task */
      1,       /* priority of the task */
      &Loop2,  /* Task handle to keep track of created task */
      0);      /* pin task to core 0 */

  delay(500);
}

void loop2( void * parameter) {
  while(true){
    Serial.printf("%i: ",a);
    Serial.print("This Task run on: ");
    Serial.println(xPortGetCoreID());
    a++;
    delay(2000);
  }
}

void loop(){
  Serial.printf("%i: ",a);
  Serial.print("This Task run on: ");
  Serial.println(xPortGetCoreID());
  a++;
  delay(2000);
}