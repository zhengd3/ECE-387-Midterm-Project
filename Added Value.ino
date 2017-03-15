//Constants:
const int flexPin = A0;  //pin A0 to read analog input

//Variables:
int value; //save analog value

const float Straight = 10000.0; // resistance when straight
const float Bend = 65000.0;		// resistance when bend
const float R2 = 24400.0;  		// Constant resistor
const float VCC = 5.0;			// Voltage source

void setup()
{
  Serial.begin(9600);       //Begin serial communication
}

void loop()
{
   // Read the analog value (ADC), and calculate voltage and resistance from it
  value = analogRead(flexPin);         //Read and save analog value from flex sensor
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