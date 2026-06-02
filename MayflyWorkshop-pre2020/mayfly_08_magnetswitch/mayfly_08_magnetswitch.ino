//Grove magnetic switch test sketch

//Connect the Grove Magnet Switch to the D10-11 Grove socket on the Mayfly
//Optional:  Connect a Grove Buzzer to the D4-7 Grove socket on the Mayfly
 

#define MAGNECTIC_SWITCH 10   //magnet switch input on pin D10
#define buzzer  4             //buzzer output on pin D4
int tips = 0;                 //integer with initial value of 0

void setup()
{
        Serial.begin(57600);
        pinMode(MAGNECTIC_SWITCH, INPUT);
        pinMode(buzzer,OUTPUT);
        pinMode(22, OUTPUT);       
        digitalWrite(22, HIGH);     //turn on the power to the Grove sockets
} 
 
void loop() 
{
  if(isNearMagnet())       //if the magnetic switch is near the magnet
  {
          digitalWrite(buzzer,HIGH);
                tips++;
                Serial.println(tips);
                delay(500);
                digitalWrite(buzzer,LOW);
  }
  else
  {
    
  }
}

/*If the magnetic switch is near the magnet, it will return true, */
/*otherwise it will return false */
boolean isNearMagnet()
{
  int sensorValue = digitalRead(MAGNECTIC_SWITCH);
  if(sensorValue == HIGH)    //if the sensor value is HIGH
  {
    return true;     //yes,return true
  }
  else
  {
    return false;    //no,return false
  }
}
