/*
   This is a basic example on how to use Espalexa and its device declaration methods.
   This code is edited for controlling 4 Appliances using Alexa to local network.
   Adapty by Jean Alvarenga 31/01/2023
*/

#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#define R1 15 //13
#define R2 2  //12
#define R3 4  //10
#define R4 22 //9
#else
#include <ESP8266WiFi.h>
#define R1 13
#define R2 12
#define R3 10 //14 esp07
#define R4 9 //16  esp07
#endif

#include <Espalexa.h>
#include <Adafruit_NeoPixel.h>
#define PIN 5
#define NUMLED 30
Adafruit_NeoPixel pixels(NUMLED, PIN, NEO_BRG + NEO_KHZ400); // Library with ploblem -> (NEO_BRG = RGB)
#define DELAYLOOP 20


// prototypes
boolean connectWifi();

//callback functions
void firstLightChanged(uint8_t brightness);
void secondLightChanged(uint8_t brightness);
void thirdLightChanged(uint8_t brightness);
void fourthLightChanged(uint8_t brightness);
void fivethLightChanged(uint8_t brightness);
void sixthLightChanged(uint8_t brightness);
void seventhLightChanged(uint8_t brightness);
void eighthLightChanged(uint8_t brightness);
void ninthLightChanged(uint8_t brightness);

// Change this!!

// WiFi Credentials
const char* ssid = "your ssid";
const char* password = "your password";

// device names
String Device_1_Name = "Vermelhos";
String Device_2_Name = "Verdes";
String Device_3_Name = "Roxos";
String Device_4_Name = "Cianos";
String Device_5_Name = "Rosas";

String Device_6_Name = "Rele 1x";
String Device_7_Name = "Rele 2x";
String Device_8_Name = "Rele 3x";
String Device_9_Name = "Rele 4x";

boolean wifiConnected = false;

Espalexa espalexa;

void setup()
{
  Serial.begin(115200);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pixels.begin();

  // Initialise wifi connection
  wifiConnected = connectWifi();

  if (wifiConnected)
  {
    // Define your devices here.
    espalexa.addDevice(Device_1_Name, firstLightChanged); //simplest definition, default state off
    espalexa.addDevice(Device_2_Name, secondLightChanged);
    espalexa.addDevice(Device_3_Name, thirdLightChanged);
    espalexa.addDevice(Device_4_Name, fourthLightChanged);
    
    espalexa.addDevice(Device_5_Name, fivethLightChanged);
    espalexa.addDevice(Device_6_Name, sixthLightChanged);
    espalexa.addDevice(Device_7_Name, seventhLightChanged);
    espalexa.addDevice(Device_8_Name, eighthLightChanged);
    espalexa.addDevice(Device_9_Name, ninthLightChanged);

    espalexa.begin();

  }

  else
  {
    while (1)
    {
      Serial.println("Cannot connect to WiFi. Please check data and reset the ESP.");
      delay(2500);
    }
  }

}

void loop()
{
  espalexa.loop();
  delay(1);
}

//our callback functions
void firstLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness)
  {
    if (brightness == 255)
    {
      for(int i=0; i<NUMLED; i++) {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0)); // pixels -> Color() recebe valores RGB, de 0,0,0 até 255.255.255
        pixels.show();
        delay(DELAYLOOP);
      }
      Serial.println("Device1 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    pixels.clear();
    for(int i=0; i<NUMLED; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // pixels -> Color() recebe valores RGB, de 0,0,0 até 255.255.255
      pixels.show();
      delay(DELAYLOOP);
    }
    Serial.println("Device1 OFF");
  }
}

void secondLightChanged(uint8_t brightness)
{

  //Control the device 
  if (brightness)
  {
    if (brightness == 255)
    {
      for(int i=0; i<NUMLED; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 255, 0)); // pixels -> Color() recebe valores RGB, de 0,0,0 até 255.255.255
        pixels.show();
        delay(DELAYLOOP);
      }
      Serial.println("Device2 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    pixels.clear();
    for(int i=0; i<NUMLED; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // pixels -> Color() recebe valores RGB, de 0,0,0 até 255.255.255
      pixels.show();
      delay(DELAYLOOP);
    }
    Serial.println("Device2 OFF");
  }
}

void thirdLightChanged(uint8_t brightness)
{

  //Control the device  
  if (brightness)
  {
    if (brightness == 255)
    {
      for(int i=0; i<NUMLED; i++) {
        pixels.setPixelColor(i, pixels.Color(255, 20, 147)); // pixels -> Color() recebe valores RGB, de 0,0,0 até 255.255.255
        pixels.show();
        delay(DELAYLOOP);
      }
      Serial.println("Device3 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    pixels.clear();
    for(int i=0; i<NUMLED; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // pixels -> Color() recebe valores RGB, de 0,0,0 até 255.255.255
      pixels.show();
      delay(DELAYLOOP);
    }
    Serial.println("Device3 OFF");
  }
}

void fourthLightChanged(uint8_t brightness)
{

  //Control the device 
  if (brightness)
  {
if (brightness == 255)
    {
      for(int i=0; i<NUMLED; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 255, 255)); // pixels -> Color() recebe valores RGB, de 0,0,0 até 255.255.255
        pixels.show();
        delay(DELAYLOOP);
      }
      Serial.println("Device4 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    pixels.clear();
    for(int i=0; i<NUMLED; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // pixels -> Color() recebe valores RGB, de 0,0,0 até 255.255.255
      pixels.show();
      delay(DELAYLOOP);
    }
    Serial.println("Device4 OFF");
  }
}

void fivethLightChanged(uint8_t brightness)
{

  //Control the device 
  if (brightness)
  {
if (brightness == 255)
    {
      for(int i=0; i<NUMLED; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 206, 209)); // pixels -> Color() recebe valores RGB, de 0,0,0 até 255.255.255
        pixels.show();
        delay(DELAYLOOP);
      }
      Serial.println("Device4 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    pixels.clear();
    for(int i=0; i<NUMLED; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // pixels -> Color() recebe valores RGB, de 0,0,0 até 255.255.255
      pixels.show();
      delay(DELAYLOOP);
    }
    Serial.println("Device4 OFF");
  }
}

void sixthLightChanged(uint8_t brightness)
{
  //Control the device
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R1, LOW);
      Serial.println("Device1 OFF");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R1, HIGH);
    Serial.println("Device1 ON");
  }
}

void seventhLightChanged(uint8_t brightness)
{

  //Control the device 
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R2, LOW);
      Serial.println("Device2 OFF");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R2, HIGH);
    Serial.println("Device2 ON");
  }
}

void eighthLightChanged(uint8_t brightness)
{

  //Control the device  
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R3, LOW);
      Serial.println("Device3 OFF");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R3, HIGH);
    Serial.println("Device3 ON");
  }
}

void ninthLightChanged(uint8_t brightness)
{

  //Control the device 
  if (brightness)
  {

    if (brightness == 255)
    {
      digitalWrite(R4, LOW);
      Serial.println("Device4 OFF");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R4, HIGH);
    Serial.println("Device4 ON");
  }
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi()
{
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20) {
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state) {
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Connection failed.");
  }
  return state;
}
