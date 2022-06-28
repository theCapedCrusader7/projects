int shock=2; //Shock sensor is connected to digital pin 2
int buzzer=7; //buzzer is connected to digital pin 7
int tilt=4; //tilt sensor is connected to digital pin 4
int v;
int t1;
int currenttime;
int cnt_t=0; //number of tilts
int cnt_v=0; //number of vibrations
void setup() {
pinMode (shock,INPUT); //input from shock sensor
pinMode(tilt,INPUT); //input from tilt sensor
pinMode (buzzer, OUTPUT); //output to buzzer
pinMode(LED_BUILTIN,OUTPUT); //output to LED
Serial.begin(19200); //Baud rate
currenttime=millis(); //measures time as soon as the program starts
}
void loop() {
v = digitalRead(shock); //reads and stores input from shock sensor
t1=digitalRead(tilt); //reads and stores input from tilt sensor
//Serial.println(v);
//Serial.println(t1);
if(millis()-currenttime>=1000){ //starts loop after 1 second
currenttime=millis();
if(cnt_t>=5){ //if number of tilts is more than five
Serial.println("Level tilted."); //prints when tilt is detected
digitalWrite(buzzer,HIGH); //buzzer switches on
}
else{
digitalWrite(buzzer,LOW); //otherwise buzzer stays off
}
if(cnt_v>=5){ //if number of tilts is more than 5
Serial.println("Vibrations detected."); //prints when vibration is detected
digitalWrite(LED_BUILTIN,HIGH); //LED switches on
}
else{
digitalWrite(LED_BUILTIN,LOW); //LED switches off
}
cnt_t=0; //sets no. of tilts back to zero
cnt_v=0; //sets no. of vibrations back to zero
}
if(t1==1){ //when tilt is detected
cnt_t++; //number of tilts increases by one
}
if(v==1){ //when vibration is detected
cnt_v++; //number of vibrations increases by one
}
delay(10);
}
