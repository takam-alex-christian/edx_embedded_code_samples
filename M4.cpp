#include "mbed.h"

// pin definitions

//button pin allocations
#define BUTTON_1 p5
#define BUTTON_2 p6
#define BUTTON_3 p7
#define BUTTON_4 p8

//led pin allocation
#define LED_1 p9
#define LED_2 p10
#define LED_3 p11


//pin config

//leds first
DigitalOut led1(LED_1);
DigitalOut led2(LED_2);
DigitalOut led3(LED_3);

//buttons config
InterruptIn btn1(BUTTON_1);
InterruptIn btn2(BUTTON_2);
InterruptIn btn3(BUTTON_3);
InterruptIn btn4(BUTTON_4);

//defining isr's for out buttons

void btn1Handler();

void btn2Handler();

void btn3Handler();

void btn4Handler();



int main(){
    //we initialize the init state of every button.
    led1 = led2 = led3 = 0;
    
    //we register isr's
    btn1.rise(&btn1Handler);
    btn2.rise(&btn2Handler);
    btn3.rise(&btn3Handler);
    btn4.rise(&btn4Handler);
    
    while(true){
        
        wait_ms(100);
    }
    
}

//we implement each handler earlier defined
void btn1Handler(){
    led1 = !led1;
}

void btn2Handler(){
    led2 = !led2;
}

void btn3Handler(){
    led3 = !led3;
}

void btn4Handler(){
    led1 = led2 = led3 = 1;
}
