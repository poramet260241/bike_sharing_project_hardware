#include "configuration.h"

void deep_sleep_timer_wakeup(){
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  Serial.println("Sleep for " + String(TIME_TO_SLEEP) + "seconds");
  Serial.println();
  Serial.println();
  esp_deep_sleep_start();
  Serial.println("It's never print.");
}
