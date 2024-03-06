#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels

// create an OLED display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
const int DHT_Pin = 18;                           
float temperature ;                             
float  humidity;
float kelvin;
float fahrenheit;
DHT dht(DHT_Pin, DHT11);   
void setup() {
  Serial.begin(9600);

  // initialize OLED display with I2C address 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }
  Serial.println(("Projek Membuat Sensor suhu dan menampilkannya ke layar OLED"));
  Serial.println(("By Dimas Abi Mesti"));
  delay(2000);         
  oled.clearDisplay(); 
  oled.setTextSize(1);         
  oled.setTextColor(WHITE);    
  oled.setCursor(0, 2);       
  oled.display();              
}

void loop() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  fahrenheit=(temperature*1.8)+32;
  kelvin=temperature+273.15;

  oled.clearDisplay();
  oled.setCursor(0, 0);

  oled.setCursor(0, 12);
  oled.print("Celsius ");
  oled.println("Humidity ");
  oled.print(String(dht.readTemperature(false)));
  oled.println("     "+String(humidity));
  oled.println("Fahrenheit");
  oled.println(fahrenheit);
  oled.println("Kelvin");
  oled.println(kelvin);

  oled.setCursor(0, 24);

  oled.display();

  delay(1000);
}
