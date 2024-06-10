#include <Wire.h>
#include <Adafruit_ADS1015.h>

#define SDA_PIN 23  // Changer par le numéro de la broche SDA sur votre ESP32
#define SCL_PIN 19  // Changer par le numéro de la broche SCL sur votre ESP32

Adafruit_ADS1015 ads;

void setup() {
    Serial.begin(9600);
    Wire.begin(SDA_PIN, SCL_PIN);  // Configuration des broches SDA et SCL
    ads.begin();
}

void loop() {
    int16_t adc0 = ads.readADC_SingleEnded(0);
    float voltage = adc0 * 0.125; // Conversion de la valeur ADC en tension (mV)
  
    Serial.print("Voltage: ");
    Serial.print(voltage);
    Serial.println(" mV");

    delay(1000); // Attendre 1 seconde avant la prochaine lecture
}
