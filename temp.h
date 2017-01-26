/*
Arduino 4 digits 7 segments LED countdown timer with buzzerm from
electronicsblog.net. If You share/use this code elsewhere on the internet
please meantion this code source.
*/

// segment | Arduino board PIN number 

#define G 22
#define F 23
#define A 24
#define B 25
#define E 26
#define D 27
#define C 28
#define DP 29

// Commonn cathodes control
#define GND1 52
#define GND2 53
#define GND3 50
#define GND4 51

// buttons
/*
Button_start - start/pause timer and in setup mode inreases minutes
and seconds values
Button_set - if timer is paused it resets timer to start. Long press
activates setup mode in which button is for going through minutes, seconds setup
and leaving setup mode.


*/


#define Button_start 48
#define Button_set 49

///
#define Buzzer 46
#define LED 47 // or relay insted



int i=0; 
char run=0; // shows if timer is runnig
int b=0;  //for buttons
int c=0;
int d=0; // for buzzer
char set_mode=0; // shows if timer is in setup mode
char alarm =0;  // if "1" buzzer is on



//timer variables

// user setted and "turn on" values
int default_Sec=59;
int default_Min=99;

// current values
int Sec;
int Min;

//timer interrupt

ISR(TIMER1_OVF_vect) {
Sec--; // timer values decreases
TCNT1=0x0BDC;
  
}


// functions to display digits



void digit0 () {
// for 0 needed to turn ON F A B C D E segments, so:

digitalWrite(A, HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH);
digitalWrite(F, HIGH);

//////////////////////// G segment should be turn OFF
digitalWrite(G, LOW);



};



void digit1 () {


digitalWrite(A,LOW);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(F, LOW);
digitalWrite(G, LOW);
};

void digit2 () {


digitalWrite(A,HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, LOW);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH);
digitalWrite(F, LOW);
digitalWrite(G, HIGH);
};


void digit3 () {


digitalWrite(A,HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, LOW);
digitalWrite(F, LOW);
digitalWrite(G, HIGH);
};

void digit4 () {


digitalWrite(A,LOW);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, LOW);
digitalWrite(E, LOW);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);
};

void digit5 () {


digitalWrite(A,HIGH);
digitalWrite(B, LOW);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, LOW); 
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);
};

void digit6 () {


digitalWrite(A,HIGH);
digitalWrite(B, LOW);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH); 
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);
};

void digit7 () {


digitalWrite(A,HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, LOW);
digitalWrite(E, LOW); 
digitalWrite(F, LOW);
digitalWrite(G, LOW);
};


void digit8 () {


digitalWrite(A, HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, HIGH);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);



};

void digit9 () {


digitalWrite(A, HIGH);
digitalWrite(B, HIGH);
digitalWrite(C, HIGH);
digitalWrite(D, HIGH);
digitalWrite(E, LOW);
digitalWrite(F, HIGH);
digitalWrite(G, HIGH);



};


//function to display digit from inputed int

void showdigit (int digit)

{
  
 switch (digit) {
 
 case 0:
 digit0 ();
 break;
 
 case 1:
 digit1 ();
 break;
 
 case 2:
 digit2 ();
 break;
 
 case 3:
 digit3 ();
 break;
 
 case 4:
 digit4 ();
 break;
 
 case 5:
 digit5 ();
 break;
 
 case 6:
 digit6 ();
 break;
 
 case 7:
 digit7 ();
 break;
 
 case 8:
 digit8 ();
 break;
 
 case 9:
 digit9 ();
 break;
 
 default:

 
 
 break;
 
 
 
 }; 

};


// showing 4 digits
//  not only shows 4 digit number, but also there is option to turn on
//only selected digits and decimal point.

void showdigits (int number, char digit_on, char  decimal_point) 
{

  

digitalWrite(GND4, LOW);
  // e.g. we have "1234"
showdigit(number/1000);  // segments are set to display "1"
if (decimal_point&8) {digitalWrite(DP, HIGH);} else {digitalWrite(DP, LOW);};
 if (digit_on&8) {
digitalWrite(GND1, HIGH); // first digit on,
digitalWrite(GND2, LOW); // other off
digitalWrite(GND3, LOW);
 }
 delay (1);


number = number%1000;  // remainder of 1234/1000 is 234
digitalWrite(GND1, LOW); // first digit is off
 showdigit(number/100); //// segments are set to display "2"
if (decimal_point&4) {digitalWrite(DP, HIGH);} else {digitalWrite(DP, LOW);};
 if (digit_on&4) {
digitalWrite(GND2, HIGH); // second digit is on
  } delay (1);// and so on....
 
number =number%100;    
digitalWrite(GND2, LOW);
showdigit(number/10);
if (decimal_point&2) {digitalWrite(DP, HIGH);} else {digitalWrite(DP, LOW);};
 if (digit_on&2) {
digitalWrite(GND3, HIGH);
 }
 delay (1);

number =number%10; 
digitalWrite(GND3, LOW);
showdigit(number); 
if (decimal_point&1) {digitalWrite(DP, HIGH);} else {digitalWrite(DP, LOW);};
 if (digit_on&1) {
digitalWrite(GND4, HIGH); 
  }
  delay (1);

}; 

void setup()

{

  
pinMode(A, OUTPUT);
pinMode(B, OUTPUT);
pinMode(C, OUTPUT);
pinMode(D, OUTPUT);
pinMode(E, OUTPUT);
pinMode(F, OUTPUT);
pinMode(G, OUTPUT);
pinMode(DP, OUTPUT);

pinMode(GND1, OUTPUT);
pinMode(GND2, OUTPUT);
pinMode(GND3, OUTPUT);
pinMode(GND4, OUTPUT);


pinMode(Button_start, INPUT);
digitalWrite(Button_start, HIGH); //pull up resistor

pinMode(Button_set, INPUT);
digitalWrite(Button_set, HIGH); //pull up resistor

pinMode(Buzzer, OUTPUT);
pinMode(LED, OUTPUT);

TIMSK1=0x01; // enabled global and timer overflow interrupt;
TCCR1A = 0x00; // normal operation 148 page (mode0);

TCNT1=0x0BDC;

TCCR1B = 0x00; // stop hardware timer

// loading default timer values

Sec = default_Sec ; 
Min = default_Min ;



};
void loop ()

{
 //////////// button_start////////// 
  if (!digitalRead(Button_start)&&!b) {
  
  if (!set_mode) { if (run) {TCCR1B=0x00; run=0;} else {TCCR1B=0x04; run=1;}}
  
  if (set_mode==1) {Min++;} 
  
   if (set_mode==2) {Sec++;} 
      
   if (set_mode) {b=25;} else b=100;
  
         };
         
 if (!digitalRead(Button_start)&&b==1) {
     
        };       


if (!b==0) b--;

 //////////// button_set///////// 
 if (!digitalRead(Button_set)&&!c) {
  
   if(!run&&!set_mode) {Min=default_Min; Sec=default_Sec;}
            
  if (set_mode>0) set_mode++;
  
  if (set_mode==3) {set_mode=0;  default_Sec = Sec ;
default_Min = Min; }
  
   c=100;      };   
   
 if (!digitalRead(Button_set)&&c==1&&!run) {
   
     set_mode=1;
     
     c=100;
   
        };       


if (!c==0) c--;
////////////////////////////

if (set_mode) {if (Sec==60) {Sec=00;} 

 if (Min==100) {Min=0;} }

      
       else {
 
 if (Sec==-1) {Min--;Sec=59;} 
 
 }  
 
 
//decimal point indication control 

if (!set_mode) {
  
  
  if (!(Sec%2)) { showdigits (Min*100+Sec,0x0F,0x04); } //0X00

else  {showdigits (Min*100+Sec,0x0F,0x00); }; //0000

} else {
  
  if (set_mode==1) {
  
  showdigits (Min*100+Sec,0x0F,0x0C);   //XX00
                                } else { 
                     
                     
                     
                     showdigits (Min*100+Sec,0x0F,0x03);      } //00XX

}
if (run) {  // to do while timer is running; e.g. control relay 

digitalWrite(LED, HIGH);


} else digitalWrite(LED, LOW);



if ((Min==0)&&(Sec==0)&&run) {
run=0;
TCCR1B=0x00; //stop timer

//// to do after count down is finished e.g. start alarm as in this example


alarm=1;
d=500;

}

// Alarm part
if (alarm) { if (!(d%100)) { // sound 500/100= 5 times ;
  tone(Buzzer, 440, 200); }
  d--; 
  if (d==0) {alarm=0; Sec = default_Sec ;
  Min = default_Min ; // After alarm is off, timer goes to start
          }
    }  
  
};
