#pragma once
#include <Arduino.h>

//#define TEST_MODE   //used for test device without gps fix

#define SERIAL_BUAD     115200

//----- LoRa PIN-------
#define SCK_GPIO        5
#define MISO_GPIO       19
#define MOSI_GPIO       27
#define NSS_GPIO        18
#define RESET_GPIO      14
#define DIO0_GPIO       26
#define DIO1_GPIO       33
#define DIO2_GPIO       32 

//----- GPS PIN -------
#define GPS_BUAD        9600
#define GPS_RX_PIN      12
#define GPS_TX_PIN      34
#define SEND_INTERVAL   60

//----- DEEP SLEEP ----
#define uS_TO_S_FACTOR 1000000
#define TIME_TO_SLEEP 60
#define VBATT_PIN 35
