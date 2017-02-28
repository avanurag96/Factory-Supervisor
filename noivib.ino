
int led = 13;
int threshold = 500; 
int volume;
int sensor=5;
int pinSpeaker = 10; 


void setup() 
{                
  Serial.begin(9600); // For debugging
  pinMode(led, OUTPUT);
   pinMode(pinSpeaker, OUTPUT);     
    pinMode(sensor, INPUT); 
}




void loop() {
  
  volume = analogRead(A0); // Reads the value from the Analog PIN A0
  
    Serial.println("Decibel level:");
    Serial.println(volume);
    delay(100);
 
  
  if(volume>=threshold)
{
    digitalWrite(led, HIGH); //Turn ON Led
  }  
  

else
{
    digitalWrite(led, LOW); // Turn OFF Led
  }

 long measurement =TP_init();
  delay(50);
 // Serial.print("measurment = ");
  Serial.println(measurement);
	

if (measurement>1022)
	{
		
		playTone(300, 160);
    delay(150);
		
		Serial.print("Sensor Value: ");

		Serial.println(measurement);
	
	}
	else{
 
		playTone(0, 0);
                 delay(300); 

		Serial.print("Sensor Value: ");

		Serial.println(measurement);

	}

}


void playTone(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(pinSpeaker,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }
}

long TP_init(){
  delay(10);
  long measurement=pulseIn (sensor, HIGH);}



