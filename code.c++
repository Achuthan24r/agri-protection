#define PIR 2
#define FLAME 3
#define SOIL A0
#define BUZZER 4
#define RELAY 5

int soilValue;

void setup() {
  pinMode(PIR, INPUT);
  pinMode(FLAME, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RELAY, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {

  // Animal Detection
  if (digitalRead(PIR) == HIGH) {
    digitalWrite(BUZZER, HIGH);
    Serial.println("Animal Detected!");
    delay(2000);
    digitalWrite(BUZZER, LOW);
  }

  // Fire Detection
  if (digitalRead(FLAME) == LOW) {
    digitalWrite(BUZZER, HIGH);
    Serial.println("Fire Detected!");
    delay(3000);
    digitalWrite(BUZZER, LOW);
  }

  // Soil Monitoring
  soilValue = analogRead(SOIL);

  if (soilValue > 700) {  // Dry soil
    digitalWrite(RELAY, HIGH);
    Serial.println("Water Pump ON");
  } else {
    digitalWrite(RELAY, LOW);
  }

  delay(1000);
}
