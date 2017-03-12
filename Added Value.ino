/*

*/
//Constants:
const int flexPin = A0; //pin A0 to read analog input

const float STRAIGHT_RESISTANCE = 10000.0; // resistance when straight
const float BEND_RESISTANCE = 65000.0;
const float Resistor2 = 24400.0;
const float VCC = 5.0;

void setup()
{
  Serial.begin(9600);       //Begin serial communication
}

void loop()
{
   // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(flexPin);
  float flexVoltage = flexADC * VCC / 1023.0;
  float flexResistance = Resistor2 * (VCC / flexVoltage - 1.0);
  Serial.println("Resistance: " + String(flexResistance) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle = map(flexResistance, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                   0, 180.0);
  Serial.println("Bend Angle: " + String(angle) + " degrees");
  Serial.println();

  delay(200);
  
}