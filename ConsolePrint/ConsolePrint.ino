
int x = 0;
int starting_sec = 654;
int starting_min = starting_sec / 60.0;
int starting_min2 = starting_sec / 60;

void setup() {
  Serial.begin(9600);    
}

void loop() {
  Serial.print("The time is:\n");
  Serial.print(String(starting_sec)+"\n");
  Serial.print(starting_min);
  delay(1000);
  starting_sec-=1;
}

