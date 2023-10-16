#include "mbed.h"

#define BUTTON_START p5
#define BUTTON_STOP p6

#define SWITCH_1 p7
#define SWITCH_2 p8

#define LED_1 p9
#define LED_2 p10
#define LED_3 p11
#define LED_4 p12


//start and stop buttons
DigitalIn start(BUTTON_START); //1 if pressed
DigitalIn stop(BUTTON_STOP); //1 if pressed

//guard and temperature sensors
DigitalIn guard(SWITCH_1); // 1 if guards are closed
DigitalIn temp(SWTICH_2); // 1 if temperature exceeds desired point

DigitalOut l1(LED_1); //is flashing if not ready, on if ready
DigitalOut l2(LED_2); // on when motor is running
DigitalOut l3(LED_3); // guards open, shows for 0,5s
DigitalOut l4(LED_4); // in case of excess temperatur, show for 0.5s


//vars
bool motorState = false;

int isMotorReady(); //defined

void runMotor(); //defined
void stopMotor(); //defined

void flashLed1(int pinNumber);





int main()
{
    while(1) {
        if(isMotorReady()){
            if(!l1){
                l1 = 1;
            }
        }else{
            //implying motor is not ready
            for(int i = 0; i < 4; i++){
                l1 = 1;
                wait(0.1);
                l1 = 0;
            }
        }
            
        }
        wait(0.25);
    }
}

//function to check if motor is ready
bool isMotorReady(){
    bool result = false;
    
    if(guard){
        if(!temp){
            result = true;
        }else{
            //we can flash led 4 here
            l4 = 1;
            wait(0.5);
            l4 = 0;
        }
    }else{
        // we can flash led 3 here
        l3 = 1;
        wait(0.5);
        l3 = 0;
    }
    
    
    return result;
}

void runMotor(){
    motorState = true;
    
    //we can do something to signal if the motor is already running 
}

void stopMotor(){
    motorState = false;
    
    //we can do more stuff to signal if the motor is already off
}


