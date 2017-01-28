
int x = 0;
int starting_time = 654;
int starting_min = starting_time / 60;
int starting_sec = starting_time % 60;

void setup() {
  Serial.begin(9600);    
}

void loop() {
  Serial.print("The time is:\n");
  Serial.print(String(starting_min)+"\n");
  Serial.print(starting_sec);
  delay(1000);
  starting_sec-=1;
}

