#include "configuration.h"
#include "ttn.h"
#include "gps.h"

void setup() {  
  #ifdef SERIAL_BUAD
  Serial.begin(SERIAL_BUAD);
  Serial.println(F("Starting"));
  #endif
  gps_setup();
  ttn_setup();
  delay(1000);
}

void loop() {
  ttn_loop();
  gps_loop();
  
  #ifdef TEST_MODE
  gps_build_package();
  ttn_send();
    
  #else
  if(myGPS.location.isValid()){
    gps_build_package();
    ttn_send();
  }
  else{
    Serial.println(F("no GPS fix"));
    delay(10000);
  }
  #endif
}
