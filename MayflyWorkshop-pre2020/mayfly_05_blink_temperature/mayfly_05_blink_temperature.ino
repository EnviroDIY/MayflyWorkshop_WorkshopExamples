#include <Wire.h>
#include "Sodaq_DS3231.h"
#include <SDL_Arduino_SSD1306.h>    // Modification of Adafruit_SSD1306 for ESP8266 compatibility
#include <AMAdafruit_GFX.h>   // Needs a little change in original Adafruit library (See README.txt file)
#include <SPI.h>            // For SPI comm (needed for not getting compile error)

int State8 = LOW;
int State9 = LOW;

SDL_Arduino_SSD1306 display(4); // FOR I2C

int LEDtime = 1000;   //milliseconds

void setup () 
{
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

    Serial.begin(57600);
    Wire.begin();
    rtc.begin();

    Serial.println("EnviroDIY Mayfly: Blink demo with serial temperature");
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C, false);  // initialize with the I2C addr 0x3C (for the 128x64)
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Mayfly");
    display.println("Blink/Temp demo");
    display.display();
     
}

void loop () 
{
    if (State8 == LOW) {
      State8 = HIGH;
    } else {
      State8 = LOW;
    }
    digitalWrite(8, State8);
     
    State9 = !State8;
    digitalWrite(9, State9);
    
    rtc.convertTemperature();             //convert current temperature into registers
    Serial.print(rtc.getTemperature(),2); //read registers and display the temperature
    Serial.println(" deg C");
    
    display.clearDisplay(); 
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Temp:");
    display.print(rtc.getTemperature(),1);
    display.print((char)247);display.print("C");
    display.display();
   
    delay(LEDtime);
}
