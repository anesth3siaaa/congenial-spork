// THIS CODE HAS BEEN MAINLY WRITTEN USING CLAUDE SONNET 4.6.
// HUMAN INTERVENTION IS LIMITED TO MINOR CHANGES.

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define RST_PIN     9
#define SS_PIN      10
#define BUZZER_PIN  2
#define LED_PIN     A5
#define BUTTON_PIN  A4

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal lcd(3, 8, 4, 5, 6, 7);

#define FREQ_TOKEN  1000
#define FREQ_CARD   500

int scanCount = 0;

// Note
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

void playMarioLose() {
  // Melodia "game over" Super Mario
  tone(BUZZER_PIN, NOTE_C5, 300); delay(330);
  tone(BUZZER_PIN, NOTE_G4, 300); delay(330);
  tone(BUZZER_PIN, NOTE_E4, 300); delay(330);
  tone(BUZZER_PIN, NOTE_A4, 200); delay(220);
  tone(BUZZER_PIN, NOTE_B4, 200); delay(220);
  tone(BUZZER_PIN, NOTE_A4, 200); delay(220);
  tone(BUZZER_PIN, NOTE_GS4, 200); delay(220);
  tone(BUZZER_PIN, NOTE_AS4, 200); delay(220);
  tone(BUZZER_PIN, NOTE_GS4, 200); delay(220);
  tone(BUZZER_PIN, NOTE_G4, 150); delay(170);
  tone(BUZZER_PIN, NOTE_F4, 150); delay(170);
  tone(BUZZER_PIN, NOTE_G4, 500); delay(600);
  noTone(BUZZER_PIN);
}

void playTetris() {
  // Prime note Tetris (Korobeiniki)
  tone(BUZZER_PIN, NOTE_E5, 300); delay(330);
  tone(BUZZER_PIN, NOTE_B4, 150); delay(165);
  tone(BUZZER_PIN, NOTE_C5, 150); delay(165);
  tone(BUZZER_PIN, NOTE_D5, 300); delay(330);
  tone(BUZZER_PIN, NOTE_C5, 150); delay(165);
  tone(BUZZER_PIN, NOTE_B4, 150); delay(165);
  tone(BUZZER_PIN, NOTE_A4, 300); delay(450);
  noTone(BUZZER_PIN);
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Last UID:");
  lcd.setCursor(0, 1);
  lcd.print("None");
  
  Serial.println("Scanner is ready");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("None");
    scanCount = 0;
    Serial.println("Reset.");
    playMarioLose();
    delay(500);
    return;
  }

  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(rfid.uid.uidByte[i], HEX);
    if (i < rfid.uid.size - 1) uid += ":";
  }
  uid.toUpperCase();
  Serial.print("UID ");
  Serial.println(uid);

  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(uid);

  byte lastByte = rfid.uid.uidByte[rfid.uid.size - 1];
  byte lastNibble = lastByte & 0x0F;

  scanCount++;
  Serial.print("Scans: ");
  Serial.println(scanCount);

  if (scanCount % 10 == 0) {
      playTetris();
      delay(500);
      if (lastNibble == 0x1) {
        tone(BUZZER_PIN, FREQ_TOKEN, 400);
      } else if (lastNibble == 0x2) {
        tone(BUZZER_PIN, FREQ_CARD, 400);
      }
    } else if (lastNibble == 0x1) {
      tone(BUZZER_PIN, FREQ_TOKEN, 400);
    } else if (lastNibble == 0x2) {
      tone(BUZZER_PIN, FREQ_CARD, 400);
    } else {
    Serial.println("Unable to recognize tag.");
    tone(BUZZER_PIN, 200, 200); delay(300);
    tone(BUZZER_PIN, 200, 200); delay(300);
    noTone(BUZZER_PIN);
  }

  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(200);
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
