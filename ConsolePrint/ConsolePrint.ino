#include stdio.h

int x = 0;
int starting_time = 654;
int starting_min = starting_time / 60;
int starting_sec = starting_time % 60;
unsigned long time;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(9600);    
}

void loop() {
  Serial.println("The time is:");
  Serial.println(String(starting_min+":"+String(starting_sec)));

  delay(1000);
  starting_sec-=1;
}

