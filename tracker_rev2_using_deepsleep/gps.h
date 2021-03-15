#include <TinyGPS++.h>
#include "configuration.h"

TinyGPSPlus myGPS;
HardwareSerial _serial_gps(1);

uint32_t LatBin;
uint32_t LonBin;

void gps_print(){
  Serial.print("Location: "); 
  if (myGPS.location.isValid()) 
  {
    Serial.print(myGPS.location.lat(), 6);
    Serial.print(F(", "));
    Serial.print(myGPS.location.lng(), 6);
    Serial.print(F("\t"));
  } 
  else 
  {                                      
    Serial.print(F("INVALID"));
  }
  Serial.println();
}

uint8_t get_speed_mps(){
  double device_speed = myGPS.speed.mps();
  uint8_t device_speed_char = device_speed*100;
  Serial.println("SPEED: " + (String)device_speed);
  Serial.println("SPEED DATA: " + (String)device_speed_char + "mps");
  return device_speed_char;
}

void gps_build_package(){

    gps_print();

    #ifdef TEST_MODE
    LatBin = ((7.008120 + 90) / 180.0) * 16777215;
    LonBin = ((100.504173 + 180) / 360.0) * 16777215;
    #else
    LatBin = ((myGPS.location.lat() + 90) / 180.0) * 16777215;
    LonBin = ((myGPS.location.lng() + 180) / 360.0) * 16777215;
    #endif
    
    mydata[0] = ( LatBin >> 16 ) & 0xFF;
    mydata[1] = ( LatBin >> 8 ) & 0xFF;
    mydata[2] = LatBin & 0xFF;
    mydata[3] = ( LonBin >> 16 ) & 0xFF;
    mydata[4] = ( LonBin >> 8 ) & 0xFF;
    mydata[5] = LonBin & 0xFF;
    mydata[6] = get_speed_mps();

}

void gps_setup(){
  _serial_gps.begin(GPS_BUAD, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
}

void gps_loop(){
    while(_serial_gps.available()){
      myGPS.encode(_serial_gps.read());
    }
}
