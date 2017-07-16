#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>

#define LED 13
#define ONE_WIRE_BUS 1

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, LED, NEO_GRB + NEO_KHZ800);

float temp = 0;
const char* server = "server name";
const char* ssid = "ssid"; 
const char* pass= "password";
int sent = 0;

void setup() {
  Serial.begin(115200);
  //setting up the led
  strip.begin();
  sensors.begin();
  strip.show();
  //connecting to wifi
  Serial.print("Connecting to "+*ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connection successful");
  Serial.println("");
}

void loop() {
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); 
  Serial.print("Current temperature: ");
  temp=sensors.getTempCByIndex(0);
  Serial.print(temp);
  if(temp<20)
    strip.setPixelColor(0, 0, 0, 255);
  if(temp>20&&temp<27)
    strip.setPixelColor(0, 0, 255,0);
  if(temp>27)
    strip.setPixelColor(0, 255, 0, 0);
  strip.show();
}

void postTemperature(){
    //todo  send json to the server here
}

