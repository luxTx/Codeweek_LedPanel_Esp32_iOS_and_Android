/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.8 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.1 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "Led-Panel" // Name des LED-Panels


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 35 bytes
  { 255,4,0,0,0,28,0,16,8,1,6,0,4,33,55,55,2,26,2,1,
  11,8,41,11,2,26,31,31,79,78,0,79,70,70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t rgb_1_r; // =0..255 Red color value 
  uint8_t rgb_1_g; // =0..255 Green color value 
  uint8_t rgb_1_b; // =0..255 Blue color value 
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
#include <Adafruit_NeoPixel.h>
#define LED_CHIPSET WS2812B
int PIN = 18;
int NUM_LEDS = 39;
int BRIGHTNESS = 5;
int delayval = 10;

Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int AN = 1;      

void setup() 
{
  RemoteXY_Init (); 
  
  // TODO you setup code
  leds.begin();
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  if(RemoteXY.switch_1 == AN){
    for(int i=0;i<NUM_LEDS;i++){
      leds.setPixelColor(i, leds.Color(RemoteXY.rgb_1_r,RemoteXY.rgb_1_g,RemoteXY.rgb_1_b)); // Defines the color picked on the colorWheel
      leds.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); // Delay for a period of time (in milliseconds).
      }
        }else{
          for(int i=0;i<NUM_LEDS;i++){
            leds.setPixelColor(i, leds.Color(0,0,0)); // Define OFF state of leds
            leds.show(); // This sends the updated pixel color to the hardware.
            delay(delayval); // Delay for a period of time (in milliseconds).
            }
  }   
}
