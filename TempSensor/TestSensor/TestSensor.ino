#include <dht.h>

#define DHTTYPE DHT11

dht DHT;
#define DHT11_PIN 8

//const int dhtPin = 8;

//DHT dht(dhtPin, DHTTYPE);

void setup(void) {
    Serial.begin(115200);
    Serial.print("LIBRARY VERSION: ");
    Serial.println(DHT_LIB_VERSION);
    Serial.println();
    Serial.println("Type, \tstatus, \tHumidity (%), \tTemperature (C)");
}

void loop(void) {
    DHT.read11(DHT11_PIN);
    float h = DHT.humidity;
    float t = DHT.temperature;

    if (isnan(t) || isnan(h)) {
        Serial.println("DHT ERROR");
    } else {
        Serial.print("T: ");
        Serial.print(t);
        Serial.print("C\t");
        Serial.print("H: ");
        Serial.print(h);
        Serial.println("%");
    }

    delay(2000);
}
