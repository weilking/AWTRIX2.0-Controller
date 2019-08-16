//This is only a test...

#include <FS.h>
#include <spi.h>
//#include <ArduinoOTA.h>           //https://lastminuteengineers.com/esp32-ota-updates-arduino-ide/
#include <WiFI.h>                   //neu -> ersetzt ESP8266WiFi.h
//#include <ESP8266WiFi.h>
#include <WebServer.h>              //neu -> ersetzt ESP8266WebServer.h
//#include <ESP8266WebServer.h>
//#include <ESP32httpUpdate>        //neu -> ersetzt ESP8266httpUpdate.h  (muss noch installiert werden...)
//#include <ESP8266httpUpdate.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>
#include <Fonts/TomThumb.h>
#include <LightDependentResistor.h>
#include <Wire.h>
#include <SparkFun_APDS9960.h>
//#include "SoftwareSerial.h"
#include <DFPlayerMini_Fast.h>
#include <WiFiManager.h>
//#include <DoubleResetDetect.h>
#include <Wire.h>
#include <BME280_t.h>
#include "Adafruit_HTU21DF.h"
#include <LiquidCrystal.h>


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Arduino.h"

#define LCD_RS 22
#define LCD_E 23
#define LCD_D4 5
#define LCD_D5 18
#define LCD_D6 19
#define LCD_D7 21

TaskHandle_t Loop2;
LiquidCrystal lcd(LCD_RS,LCD_E,LCD_D4,LCD_D5,LCD_D6,LCD_D7);	//RS - E - D4 - D5 - D6 - D7

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
  /*
  pinMode(LCD_RS,OUTPUT);
	pinMode(LCD_E,OUTPUT);
	pinMode(LCD_D4,OUTPUT);
	pinMode(LCD_D5,OUTPUT);
	pinMode(LCD_D6,OUTPUT);
	pinMode(LCD_D7,OUTPUT);
  */

	lcd.begin(16,2);
	lcd.clear();
	lcd.setCursor(0,0); // Cursor Zeile 0 setzen
	lcd.print("2x16 LCD TESTAUSGABE"); // Text ausgeben
	lcd.setCursor(0,1); // C


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