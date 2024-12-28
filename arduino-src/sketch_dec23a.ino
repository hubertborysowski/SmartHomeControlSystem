void setup() {
    Serial.begin(9600);
    delay(1000);  // Allow time for serial communication to initialize
}

void loop() {
    if (Serial.available()) {
        String incomingString = Serial.readString();  // Read the entire incoming string
        Serial.print(incomingString);  // Echo back the string
        delay(500);
    }
    delay(10);  // Small delay to allow serial buffer to process
}