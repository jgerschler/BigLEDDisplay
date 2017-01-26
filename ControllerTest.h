/*
7-Segment counter for homemade display using four digits, common anodes.
Segment letters begin at top segment (A), going clockwise. Center segment is G.
*/

// segment  - pin number 

#define A 22
#define B 23
#define C 24
#define D 25
#define E 26
#define F 27
#define G 28

// common anodes

#define ANODE1 50
#define ANODE2 51
#define ANODE3 52
#define ANODE4 53

int timer=0;

int i=0;

// digit display functions

void digit8() {
	
	digitalWrite(A, HIGH);
	digitalWrite(B, HIGH);
	digitalWrite(C, HIGH);
	digitalWrite(D, HIGH);
	digitalWrite(E, HIGH);
	digitalWrite(F, HIGH);
	digitalWrite(G, HIGH);
	
};

// setup

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
	
};

// main loop

void loop() {
	
	timer++;
	
	displaySingleDigit(i);
	
	if (timer == 10) {
		
		timer = 0;
		i++;
		
		if (i>1000) {i = 0;};
		
	}
	
};