// Define the pins for LEDs and switches
const int ledGreen = 12;
const int ledYellow = 10;
const int switchPin1 = 2;
const int switchPin2 = 4;

// Define the beats per minute (BPM) for the song
const int beatsPerMinute = 104; // Adjust this value if needed

// Calculate the duration of each beat in milliseconds
const int beatDuration = 60000 / beatsPerMinute;

// Variables to track switch states
int switchState1 = 0;
int switchState2 = 0;
int lastSwitchState1 = 0;
int lastSwitchState2 = 0;

// Variables to control LED blinking
unsigned long previousMillis = 0;
int ledStateGreen = LOW;
int ledStateYellow = LOW;

// Morse code for "ALL CLEAR"
const int allClearDuration = 200; // Duration of each dot or dash in milliseconds

const int allClearPattern[] = {
  allClearDuration, allClearDuration, allClearDuration, // A
  allClearDuration, allClearDuration, allClearDuration, // L
  allClearDuration * 3, // Space between words
  allClearDuration, allClearDuration, allClearDuration, allClearDuration, allClearDuration, allClearDuration, allClearDuration // C
};
const int allClearLength = sizeof(allClearPattern) / sizeof(allClearPattern[0]);

// Morse code for "SOS"
const int sosPattern[] = {
  allClearDuration, allClearDuration, allClearDuration, // S
  allClearDuration * 3, // Space between letters
  allClearDuration, allClearDuration, allClearDuration, // O
  allClearDuration * 3, // Space between letters
  allClearDuration, allClearDuration, allClearDuration // S
};
const int sosLength = sizeof(sosPattern) / sizeof(sosPattern[0]);

// Counter for beats
int beatCounter = 0;

void setup() {
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
}

void loop() {
  // Read the state of the switches
  switchState1 = digitalRead(switchPin1);
  switchState2 = digitalRead(switchPin2);

  // Check if the switches are ON (HIGH since INPUT_PULLUP is used)
  if (switchState1 == HIGH || switchState2 == HIGH) {
    // Get the current time
    unsigned long currentMillis = millis();

    // Check if enough time has passed for a new beat
    if (currentMillis - previousMillis >= beatDuration) {
      // Save the current time for the next beat
      previousMillis = currentMillis;

      // Increment the beat counter
      beatCounter++;

      // Check if switch 1 is ON (Green LEDs for "ALL CLEAR")
      if (switchState1 == HIGH) {
        // Blink "ALL CLEAR" using green LEDs
        if (beatCounter <= allClearLength) {
          int duration = allClearPattern[beatCounter - 1];
          ledStateGreen = !ledStateGreen; // Toggle the green LED state
          digitalWrite(ledGreen, ledStateGreen);
          delay(duration); // Blink duration
          ledStateGreen = LOW; // Turn off the green LED
          digitalWrite(ledGreen, ledStateGreen);
          delay(allClearDuration); // Time between dots and dashes
        }
      }
      
      // Check if switch 2 is ON (Yellow LEDs for "SOS")
      if (switchState2 == HIGH) {
        // Blink "SOS" using yellow LEDs
        if (beatCounter <= sosLength) {
          int duration = sosPattern[beatCounter - 1];
          ledStateYellow = !ledStateYellow; // Toggle the yellow LED state
          digitalWrite(ledYellow, ledStateYellow);
          delay(duration); // Blink duration
          ledStateYellow = LOW; // Turn off the yellow LED
          digitalWrite(ledYellow, ledStateYellow);
          delay(allClearDuration); // Time between dots and dashes
        }
      }

      // If the song is finished, reset the beat counter
      if (beatCounter >= allClearLength || beatCounter >= sosLength) {
        beatCounter = 0;
      }
    }
  } else {
    // If both switches are OFF (LOW since INPUT_PULLUP is used), turn off both LEDs
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    // Reset the beat counter when both switches are OFF
    beatCounter = 0;
  }

  // Save the current switch states for the next iteration
  lastSwitchState1 = switchState1;
  lastSwitchState2 = switchState2;
}
