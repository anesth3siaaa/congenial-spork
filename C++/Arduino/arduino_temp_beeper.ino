// THIS CODE HAS BEEN MAINLY WRITTEN USING CLAUDE SONNET 4.6
// HUMAN INTERVENTION IS LIMITED TO MINOR CHANGES.

#include "DHT.h"

#define DHTPIN 2      
#define DHTTYPE DHT11
#define BUZZER1 10

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(BUZZER1, OUTPUT);
}

void loop() {
  float humidity = dht.readHumidity();

  if (isnan(humidity)) {
    Serial.println("Errore: Impossibile leggere dal sensore!");
  } else {
    Serial.print("Umidità attuale: ");
    Serial.print(humidity);
    Serial.println("%");

    // Se l'umidità è >= 75%, emette un secondo beep rapido
    if (humidity >= 75.0) {
      tone(BUZZER1, 600, 40); // Secondo beep
      delay(1000);
      tone(BUZZER1, 1000, 40);
    } else {
      tone(BUZZER1, 600, 40);
    }
  }
    if (humidity >= 75.0) {
      delay(1000);
    } else {
      delay(2000);
    }
}
