
int l2=13;
void setup() {
  
Serial.begin(38400);

//S.println("AT");
delay(1000);
 pinMode(12, OUTPUT); // put your setup code here, to run once:
 }

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {     
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case '1': digitalWrite(12, HIGH);break; // when a is pressed on the app on your smart phone
        case '0': digitalWrite(12, LOW);break; // when d is pressed on the app on your smart phone
        default : break;
      }
      Serial.println(data);
   }
   delay(50);
}
