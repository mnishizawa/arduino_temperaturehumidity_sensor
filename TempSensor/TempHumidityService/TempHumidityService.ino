#include <dht.h>
#include <Bridge.h>

#define DHTTYPE DHT11

dht DHT;

const int dhtPin=8;

#define DHT11_PIN dhtPin

void setup(void) {
    Bridge.begin();
    
    pinMode(dhtPin, INPUT);
    
}

void loop(void) {
    DHT.read11(DHT11_PIN);
    float h = DHT.humidity;
    float t = DHT.temperature;

    Bridge.put(String("humidity"), String(h));
    Bridge.put(String("temperature"), String(t));

    delay(5   000);
}
