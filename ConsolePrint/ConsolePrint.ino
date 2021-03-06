int x = 0;
int starting_time = 654;
int starting_min = starting_time / 60;
int starting_sec = starting_time % 60;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(9600);
  Serial.println("The time is:");
  Serial.println(String(starting_min+":"+String(starting_sec)));    
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    starting_time-=1;
    starting_min = starting_time / 60;
    starting_sec = starting_time % 60;
    Serial.println("The time is:");
    Serial.println(String(starting_min)+":"+String(starting_sec));
  }
}

