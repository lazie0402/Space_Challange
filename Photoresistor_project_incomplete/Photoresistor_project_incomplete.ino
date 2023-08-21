int sensorPin = A0; // set the analog zero input pin to probe the photoresistor 
int onboardLED = 13; // selecting the builtin led 
int sensorValue = 0; // holding spot for read value from the sensor
int LED = 12; // LED on pin 12 
unsigned int batteryCap = 50000;
unsigned int batterylvl = 0;
unsigned int ticks = 0;
unsigned int wait = 10 ; 
double PercentFull;



void setup() {
  // put your setup code here, to run once:

pinMode(onboardLED, OUTPUT);
pinMode(LED, OUTPUT);
Serial.begin(9600);

}
void Printbatpercent() {
  // print the elapsed time
  Serial.print(ticks);
  Serial.print(" ms  charge at ");

  // conver ints into decimals devid them and print
  PercentFull=100*((double)batterylvl / (double)batteryCap);
  Serial.print(PercentFull);

  //print a percent sign and line return
  Serial.println("%");

}
void loop() {
  // put your main code here, to run repeatedly:
sensorValue = analogRead(sensorPin);
batterylvl += sensorValue;
ticks += wait;
 
  if(batterylvl >= batteryCap) {
    Serial.print(ticks);
    Serial.print(" ms     ");
    Serial.println("FULLY CHARGED");
    digitalWrite(LED, HIGH);
    batterylvl = batteryCap; // to prevent integer from continuing to increase
    ticks = 0;
    delay(20000);      // long pause
  }
  else {
    Printbatpercent();

    // Calculate the blinking delay based on the sensorValue
    int blinkingDelay = map(sensorValue, 700, 0, 100, 500); // Adjust these values for desired blinking range

    digitalWrite(LED, HIGH);
    delay(blinkingDelay);
    digitalWrite(LED, LOW);
    delay(blinkingDelay);
  }

  delay(wait);
}