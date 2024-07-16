#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;  // Crear el objeto ADS1115

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Inicializando ADS1115...");
  
  // Iniciar el ADS1115 en la dirección I2C 0x48
  if (!ads.begin(0x48)) {
    Serial.println("No se encontró el ADS1115. Verifica la conexión.");
    while (1);
  }
}

void loop(void)
{
  int16_t adc0, adc1, adc2, adc3;
  
  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);
  
  Serial.print("AIN0: "); Serial.println(adc0);
  Serial.print("AIN1: "); Serial.println(adc1);
  Serial.print("AIN2: "); Serial.println(adc2);
  Serial.print("AIN3: "); Serial.println(adc3);
  Serial.println("----");
  
  delay(1000);
}
