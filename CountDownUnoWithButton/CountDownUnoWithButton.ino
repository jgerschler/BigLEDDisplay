// segment  - pin number 
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

// common anodes
#define ANODE1 9
#define ANODE2 10
#define ANODE3 11
#define ANODE4 12

int x = 0;
int starting_time = 120;// starting time in seconds
int starting_min = starting_time / 60;
int starting_sec = starting_time % 60;
unsigned long refreshMillis = 0;
unsigned long clockMillis = 0;
const long refreshInterval = 10;
const long clockInterval = 1000;

// digit display functions
void digit0() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void digit1() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void digit2() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void digit3() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void digit4() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void digit5() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void digit6() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void digit7() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void digit8() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void digit9() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

// function to display single digit
void displaySingleDigit (int digit) {
  switch(digit) {
    
    case 0:
      digit0();
      break;
      
    case 1:
      digit1();
      break;    
    
    case 2:
      digit2();
      break;    

    case 3:
      digit3();
      break;

    case 4:
      digit4();
      break;

    case 5:
      digit5();
      break;

    case 6:
      digit6();
      break;

    case 7:
      digit7();
      break;

    case 8:
      digit8();
      break;

    case 9:
      digit9();
      break;  
  }
}

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  
  pinMode(ANODE1, OUTPUT);
  pinMode(ANODE2, OUTPUT);
  pinMode(ANODE3, OUTPUT);
  pinMode(ANODE4, OUTPUT);    
}

void displayOut(){
  int digit1 = starting_min / 10;
  int digit2 = starting_min % 10;
  int digit3 = starting_sec / 10;
  int digit4 = starting_sec % 10;
  
  displaySingleDigit(digit1);
  digitalWrite(ANODE1, HIGH);
  delay(1);
  digitalWrite(ANODE1, LOW);
  displaySingleDigit(digit2);  
  digitalWrite(ANODE2, HIGH);
  delay(1);
  digitalWrite(ANODE2, LOW);
  displaySingleDigit(digit3);
  digitalWrite(ANODE3, HIGH);  
  delay(1);
  digitalWrite(ANODE3, LOW);
  displaySingleDigit(digit4);
  digitalWrite(ANODE4, HIGH);
  delay(1);
  digitalWrite(ANODE4, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  displayOut();

  if (currentMillis - clockMillis >= clockInterval) {
    clockMillis = currentMillis;
    starting_time-=1;
    starting_min = starting_time / 60;
    starting_sec = starting_time % 60;
  }
}

