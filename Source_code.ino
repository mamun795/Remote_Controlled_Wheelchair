char data; // Stores the received command

void setup() {
  Serial.begin(9600); // Serial communication with the Bluetooth module

  // Motor driver pins
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.println(data); // For debugging

    switch (data) {
      case 'F': // Forward
        digitalWrite(3, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        break;
      case 'B': // Backward
        digitalWrite(3, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        break;
      case 'R': // Right: left motor forward, right motor backward
        digitalWrite(3, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        break;
      case 'L': // Left: left motor backward, right motor forward
        digitalWrite(3, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        break;
      case 'S': // Stop
        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        break;
    }
  }
}