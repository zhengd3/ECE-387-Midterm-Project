/*

*/
//Constants:
const int ledPinR = 3;   //pin 3 has PWM funtion
const int ledPinG = 6;
const int flexPin = A0; //pin A0 to read analog input

//Variables:
int valueR; //save analog value
int valueG;

const float straight = 10000.0; // resistance when straight
const float bend = 65000.0;
const float Resistor2 = 24400.0;
const float VCC = 5.0;

void setup()
{
  
  pinMode(ledPinR, OUTPUT);  //Set pin 3 as 'output'
  pinMode(ledPinG, OUTPUT);
  Serial.begin(9600);       //Begin serial communication

}

void loop()
{
  valueR = analogRead(flexPin);         //Read and save analog value from flex sensor
  valueG = analogRead(flexPin); 
  Serial.println("Value is: " + String(valueR));  //Print value
  //Serial.println(valueG);
  valueR = map(valueR, 50, 700, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  valueG = map(valueG, 700, 270, 0, 255);
  analogWrite(ledPinR, valueR);          //Send PWM value to led
  analogWrite(ledPinG, valueG);
  
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////
  //Added Value
  ///////////////////////////////////////////////////////////////////////////////////////////////////
   // Read the ADC, and calculate voltage and resistance from it
  int flexADC = analogRead(flexPin);
  float flexVoltage = flexADC * VCC / 1023.0;
  float flexResistance = Resistor2 * (VCC / flexVoltage - 1.0);
  Serial.println("Resistance: " + String(flexResistance) + " ohms");

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle = map(flexResistance, straight, Bend,
                   0, 180.0);
  Serial.println("Bend Angle: " + String(angle) + " degrees");
  Serial.println();

  delay(200);
  
}
