int Light = 12 ; //Hero board pin 12 is names light
int Switch1 = 2; //swith 1 on pin 3
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Light, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    if (digitalRead(Switch1) == HIGH){
    digitalWrite(LED_BUILTIN, HIGH); 
    digitalWrite(Light, HIGH); //Turn on 
    delay(500);
  digitalWrite(LED_BUILTIN, HIGH); 
  digitalWrite(Light, HIGH);
  // turn the LED on (HIGH is the voltage level)
  delay(150);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(Light, LOW);   // turn the LED off by making the voltage LOW
  delay(150);                      // wait for a second
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(Light, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(150);  
  delay(1000);                    // wait for a second
  digitalWrite(LED_BUILTIN, LOW); 
  digitalWrite(Light, LOW);  // turn the LED off by making the voltage LOW
  delay(150);                      // wait for a second
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(Light, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(150);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(Light, LOW);  
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(Light, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(150);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(Light, LOW); // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
  }
  else {
    digitalWrite(Light, LOW); //led turned off 
  }}
