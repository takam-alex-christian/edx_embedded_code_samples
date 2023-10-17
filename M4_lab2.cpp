#include "mbed.h"

#define BUTTON_1 p5
#define BUTTON_2 p6 
#define BUTTON_3 p7 
#define BUTTON_4 p8 

#define RED_LED p9
#define YELLOW_LED p10
#define BLUE_LED p11

//Define outputs
DigitalOut l1(RED_LED);
DigitalOut l2(YELLOW_LED);
DigitalOut l3(BLUE_LED);


//Define interrupt inputs
InterruptIn btn1(BUTTON_1);
InterruptIn btn2(BUTTON_2);
InterruptIn btn3(BUTTON_3);
InterruptIn btn4(BUTTON_4);

//Define counters
volatile unsigned int count1;
volatile unsigned int count2;
volatile unsigned int count3;

void updateLEDs(){
    if(count1>count2&&count1>count3) {l1 = 1; l2 = l3 = 0;}
    else if(count2>count1 && count2>>count3) {l2 =1; l1 = l3 = 0;}
    else if (count3 > count2 && count3> count1) {l3 = 1; l1=l2=0;}
}


//Define ISRs for the interrupts
void button_1_handler(){
	
	count1++;
	
	updateLEDs();
	
}

void button_2_handler(){
	
	count2++;
	
	updateLEDs();
	
}

void button_3_handler(){
	
	count3++;
	updateLEDs();
}

void button_4_handler(){
	
    //works as a reset button
    
    count1 = count2 = count3 = 0;
    
    l1 = l2 = l3 = 0;
	
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
    
    
		
	//Initially turn off all LEDs and set all the counters to 0
	l1 = l2 = l3 = 0;
	count1=count2=count3 = 0;
	//Write your code here
    
    
	//Interrupt handlers
	btn1.rise(&button_1_handler);
	btn2.rise(&button_2_handler);
	btn3.rise(&button_3_handler);
	btn4.rise(&button_4_handler);
	//Write your code here

	//wait 100 ms
	while(1)
		wait_ms(100);
}
