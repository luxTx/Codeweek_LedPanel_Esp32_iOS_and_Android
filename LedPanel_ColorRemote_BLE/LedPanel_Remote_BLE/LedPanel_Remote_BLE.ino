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
#define REMOTEXY_BLUETOOTH_NAME "Led-Panel"                                // NAME DES LED PANELS


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 43 bytes
  { 255,5,0,0,0,36,0,16,8,1,6,0,5,43,55,55,2,26,2,1,
  38,5,23,7,2,26,31,31,79,78,0,79,70,70,0,3,3,9,5,12,
  34,2,26 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t rgb_1_r; // =0..255 Red color value 
  uint8_t rgb_1_g; // =0..255 Green color value 
  uint8_t rgb_1_b; // =0..255 Blue color value 
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  uint8_t select_1; // =0 if select position A, =1 if position B, =2 if position C, ... 

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
int NUM_LEDS = 39;                                                            // ANZAHL AN LEDS
int BRIGHTNESS = 5;
int delayval = 32;
uint8_t value = (RemoteXY.rgb_1_r + RemoteXY.rgb_1_g + RemoteXY.rgb_1_b)/3;

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
    switch (RemoteXY.select_1) {
      case 0:
        colorWheel();
        break;
      case 1:
        rainbow();
        break;
      case 2:
        ledOff();
        meteorRain(RemoteXY.rgb_1_r,RemoteXY.rgb_1_g,RemoteXY.rgb_1_b,10, 64, true, 30);
        break;
      default:
          colorWheel();
      }
        }else{
          ledOff();     
  }   
}

void ledOff(){
  for(int i=0;i<NUM_LEDS;i++){
            leds.setPixelColor(i, leds.Color(0,0,0)); // Moderately bright green color.
            leds.show(); // This sends the updated pixel color to the hardware.
            delay(delayval); // Delay for a period of time (in milliseconds).
            }
  }

void colorWheel(){
  for(int i=0;i<NUM_LEDS;i++){
          leds.setPixelColor(i, leds.Color(RemoteXY.rgb_1_r,RemoteXY.rgb_1_g,RemoteXY.rgb_1_b)); // Moderately bright green color.
          leds.show(); // This sends the updated pixel color to the hardware.
          delay(delayval); // Delay for a period of time (in milliseconds).
        }
  }

void rainbow(){
  for(long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 22) {
      for(int i=0; i<NUM_LEDS; i++) { 
          int pixelHue = firstPixelHue + (i * 65536L / NUM_LEDS);
          leds.setPixelColor(i, leds.gamma32(leds.ColorHSV(pixelHue,255,RemoteXY.rgb_1_r)));
        }
        leds.show();
  }
}

void meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {  
  leds.clear();
 
  for(int i = 0; i < NUM_LEDS+NUM_LEDS; i++) {
   
   
    // fade brightness all LEDs one step
    for(int j=0; j<NUM_LEDS; j++) {
      if( (!meteorRandomDecay) || (random(10)>5) ) {
        fadeToBlack(j, meteorTrailDecay );        
      }
    }
   
    // draw meteor
    for(int j = 0; j < meteorSize; j++) {
      if( ( i-j <NUM_LEDS) && (i-j>=0) ) {
        leds.setPixelColor(i-j, red, green, blue);
      }
    }
   
    leds.show();
    delay(75);       // SCHNELLIGKEIT
  }
}

void fadeToBlack(int ledNo, byte fadeValue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
    // NeoPixel
    uint32_t oldColor;
    uint8_t r, g, b;
    int value;
   
    oldColor = leds.getPixelColor(ledNo);
    r = (oldColor & 0x00ff0000UL) >> 16;
    g = (oldColor & 0x0000ff00UL) >> 8;
    b = (oldColor & 0x000000ffUL);

    r=(r<=10)? 0 : (int) r-(r*fadeValue/256);
    g=(g<=10)? 0 : (int) g-(g*fadeValue/256);
    b=(b<=10)? 0 : (int) b-(b*fadeValue/256);
   
    leds.setPixelColor(ledNo, r,g,b);
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[ledNo].fadeToBlackBy( fadeValue );
 #endif  
}
