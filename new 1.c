#include <xc.h>
#include <pic.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 #pragma config FOSC=HS, CP=OFF, DEBUG=OFF, BORV=20, BOREN=0, MCLRE=ON, PWRTE=ON, WDTE=OFF
 #pragma config BORSEN=OFF, IESO=OFF, FCMEN=0
 /* Variable declarations */
#define PORTBIT(adr,bit) ((unsigned)(&adr)*8+(bit))
// The function PORTBIT is used to give a name to a bit on a port
// The variable RC0 could have equally been used
 static bit greenButton @ PORTBIT(PORTC,0);
 static bit redButton @ PORTBIT(PORTC,1);
 static bit UniH @ PORTBIT(PORTC,4); //the horizontal interrupter of the unipolar stepper
 static bit UniV @ PORTBIT(PORTC,5); //the vertical interrupter of the unipolar stepper
 static bit BiV  @ PORTBIT(PORTC,6); //the vertical interrupter of the bipolar stepper
 static bit BiH @ PORTBIT(PORTC,7); //the horizontal interrupter of the bipolar stepper
  char  i,Temp; // Variable for delay loop 
 char State; //State is a variable for holding the state of the program
 
  void UniCW(void)
 void main (void)
{ 
 //init???about reset
 PORTB = 0B00000000; // Set PORTB low
 TRISB = 0B11110000; // Configure Port B pin 0~3 as outputs,pin 4~7 as inputs
 
 PORTC = 0B00000000; // Set PORTC low
 TRISC = 0B11110011; // Configure Port C as all input???
 
 PORTD = 0B00000000; // Set PORTD low
 TRISD = 0B00000000; // Configure Port D as all output
 
 PORTE = 0B00000000; // Set PORTE low
 TRISE = 0B00000111; // Configure Port E as all inputs
 
 ADCON1= 0B00001010;
 
 UniCW();
}
 
 
 
 
 void UniCW(void)
{
 Temp = PORTD&0B11110000;
 PORTD = Temp|0B00000011;
 delay(30);
 Temp = PORTD&0B11110000;
 PORTD=Temp|0B00000110;
 delay(30);
 Temp = PORTD&0B11110000;
 PORTD=Temp|0B00001100;
 delay(30);
 Temp = PORTD&0B11110000;
 PORTD=Temp|0B00001001;
 delay(30);
}
