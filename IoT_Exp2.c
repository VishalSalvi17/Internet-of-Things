#include<reg51.h> 

int countS=0, countT=0;
unsigned char sine[32]={245, 234, 218, 198, 176, 152, 128, 103, 79, 57, 37, 21, 10, 2, 0, 2, 10, 21, 37, 57, 79, 103, 128, 152, 176, 198, 218, 234, 245, 253, 255, 253, };  
unsigned char trng[32]={16, 32, 48, 64, 80, 96, 112, 128, 143, 159, 175, 191, 207, 223, 239, 255, 239, 223, 207, 191, 175, 159, 143, 128, 112, 96, 80, 64, 48, 32, 16, 0}; 		
unsigned char i; 
void delay(unsigned char time); 

void timer0 (void) interrupt 1
{
	TR0=0; //stop tmer
	TF0=0; //clear flag
	if (countT<32)
	{	P2 = trng[countT];
		countT++;}
	else
	{	countT = 0;	}	
	TR0=1; //restart timer
}
	
void timer1 (void) interrupt 3
{
	TR1=0; //stop tmer
	TF1=0; //clear flag
	if (countS<32)
	{	P1 = sine[countS];
		countS++;}
	else
	{	countS = 0;	}	
	TR1=1; //restart timer
}

int main(void)  
 {  
		//Initialising both timers to generate waveforms
		IE = 0x8A; //EA=1 ET0=1 ET1=1
		TMOD = 0x22; //Both in 16bit mode
		TH0 = 0xF0; 
		TH1 = 0xF8;  
		TR0=1; //start timer 0 
		TR1=1; //start timer 1 
      
    while(1)  
    {  
				if (P1>P2)
					P3=0xFF;
				if (P1<P2)
					P3=0x00;
    } 
 } 
