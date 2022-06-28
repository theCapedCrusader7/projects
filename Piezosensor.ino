int ANALOG_PIN=A2; //sensor is connected to analog pin A2
int sensorOutput; //output of the piezo sensor
int threshold=900; //primary threshold
int mthreshold=600; //secondary threshold
int BOutput=7; //buzzer is connected to digital pin 7
void setup() {
pinMode(ANALOG_PIN,INPUT); //input from piezo sensor
Serial.begin(9600); //Baud rate
pinMode(LED_BUILTIN ,OUTPUT); //output to LED
pinMode(BOutput,OUTPUT); //output to buzzer
}
void loop() {
sensorOutput=analogRead(ANALOG_PIN); //Reads output of the sensor and stores
Serial.println(sensorOutput); //prints the output
Serial.print("\t"); //inserts space
if (sensorOutput>mthreshold and sensorOutput<threshold) //if sensor output is
between 500 and 900
{
digitalWrite(LED_BUILTIN,HIGH); //LED switches on
digitalWrite(BOutput,LOW); //buzzer stays off
delay(10);
}
else if ( sensorOutput>threshold) //if sensor output is greater than 900
{
digitalWrite(LED_BUILTIN,HIGH); //LED switches on as it is also greater than 500
digitalWrite(BOutput,HIGH); //Vbuzzer starts ringing
delay(10);
}
else{ //if sensor output is less than 500
digitalWrite(LED_BUILTIN,LOW); //LED is off
digitalWrite(BOutput,LOW); //buzzer is off
delay(10);
}
delay(100);
}
