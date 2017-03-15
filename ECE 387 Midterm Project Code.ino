//Constants:
const int ledPinR = 3;   //pin 3 has PWM function
const int ledPinG = 6;	 // pin 6 has PWM function
const int flexPin = A0;  //pin A0 to read analog input

//Variables:
int value; //save analog value

const float Straight = 10000.0; // resistance when straight
const float Bend = 65000.0;		// resistance when bend
const float R2 = 24400.0;  		// Constant resistor
const float VCC = 5.0;			// Voltage source

void setup()
{
  
  pinMode(ledPinR, OUTPUT);  //Set pin 3 as 'output'
  pinMode(ledPinG, OUTPUT);
  Serial.begin(9600);       //Begin serial communication

}

void loop()
{
  value = analogRead(flexPin);         //Read and save analog value from flex sensor
  Serial.println("Value is: " + String(value));  //Print value
  int valueR = map(value, 50, 700, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  int valueG = map(value, 700, 250, 0, 255);
  analogWrite(ledPinR, valueR);          //Send PWM value to led
  analogWrite(ledPinG, valueG);
  
   // Read the analog value (ADC), and calculate voltage and resistance from it
  float Voltage = value * VCC / 1023.0;
  float Resistance = R2 * (VCC / Voltage - 1.0);
  Serial.println("Resistance: " + String(Resistance) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle = map(Resistance, Straight, Bend, 0, 180.0);
  Serial.println("Bend Angle: " + String(angle) + " degrees");
  Serial.println();

  delay(200);
}