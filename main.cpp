#include "mbed.h"
#include"beep.h"

int morse[26] = {21,1112,1212,112,1,1211,122,1111,11,2221,
                212,1121,22,12,222,1221,2122,121,111,2,
                211,2111,221,2112,2212,1122};

DigitalOut buzzer(PTB0);
//DigitalOut myled(LED1);
/*DigitalIn gnd(PTB2);
DigitalOut zero(PTC1);
DigitalOut one(PTC2);*/
Serial pc(USBTX,USBRX);

int main(){
    int alpha_input;
    int temp,c,t;
    pc.printf("Please enter the letter to hear morse \n");
    
    while(1){
       if(pc.readable()){
           alpha_input = pc.getc();
           pc.putc(alpha_input);
           pc.printf("\n yo %d : ",(int)alpha_input);
           if(alpha_input<123 && alpha_input>96){
               alpha_input=alpha_input - 97; 
               }
               
           else if(alpha_input<91 &&alpha_input>64){
               alpha_input=alpha_input-65;
               }
               
            else{
                pc.printf("Invalid character\n");
                
                }
                
                c=alpha_input;
                
                if(c>=0 && c<26)
                {
                    temp = morse[c];
                    while(temp!=0){
                        t=temp%10;
                        temp=temp/10;
                        if(t==1){
                            buzzer=1;
                            wait(0.1);
                            buzzer=0;
                            pc.putc('.');
                            }
                            
                        else if(t==2){
                            buzzer=1;
                            wait(0.25);
                            buzzer=0;
                            pc.putc('-');
                            }
                            wait(0.2);
                        }
                    }
           wait(0.5);
           }
 }   
}