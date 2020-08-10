/*
 * GccApplication1.c
 *
 * Created: 7/9/2020 11:42:36 AM
 * Author : Osama Magdy
 */ 

#include <avr/io.h>
#include <util/delay.h>

  // void display(char x , char port);

int main(void)
{
	// Flash memory solution :
	// const unsigned char LUT [] = {0b00111111 , 0b00000110 , 0b01011011 ,0b01001111 , 0b01100110 , 0b01101101  ,  0b01111101 ,  0b00000111 , 0b01111111 ,  0b01101111  };
	
	DDRC = 0x00;
	DDRA = 0xFF;
	DDRB = 0xFF;
	char x = 0 ;
	
	PORTB = 0x00;
	PORTA = 0x00;
	PORTC = 0x01;
	
	
    /* Replace with your application code */
    while (1) 
    {
		if (x==100)
		{
			x=0;
		}
		//Flash Memory Solution
		//PORTA = LUT[x%10];
		//PORTB = LUT[x/10];
		
		// Switch Case Solution
		//display(x%10 , 'A');
		//display(x/10 , 'B');
		
		
		// BCD Solution
		PORTA = (PORTA & 0x00) | (x/10);
		PORTA = (PORTA<<4) | (x%10);
		
		while(PINC == 0x00);
		
		while(PINC == 0x01);
		x=x+1;
    }
}



// Switch case Solution 
/*
void display (char x , char port)
{
	if (port=='A')
	{
		switch(x)
		{
			case 0 :
					PORTA = 0b00111111;
					break;
			case 1 :
					PORTA = 0b00000110;
					break;
			case 2 :
					PORTA = 0b01011011;
					break;
			case 3 :
					PORTA = 0b01001111;
					break;
			case 4 :
					PORTA = 0b01100110;
					break;
			case 5 : 
					PORTA = 0b01101101;
					break;
			case 6 :
					PORTA = 0b01111101;
					break;
			case 7 :
					PORTA = 0b00000111;
					break;
			case 8 : 
					PORTA = 0b01111111;
					break;
			case 9 :
					PORTA = 0b01101111;
					break;
					
		}
		
	}
	else if (port == 'B')
	{
		switch(x)
		{
			case 0 :
			PORTB = 0b00111111;
			break;
			case 1 :
			PORTB = 0b00000110;
			break;
			case 2 :
			PORTB = 0b01011011;
			break;
			case 3 :
			PORTB = 0b01001111;
			break;
			case 4 :
			PORTB = 0b01100110;
			break;
			case 5 :
			PORTB = 0b01101101;
			break;
			case 6 :
			PORTB = 0b01111101;
			break;
			case 7 :
			PORTB = 0b00000111;
			break;
			case 8 :
			PORTB = 0b01111111;
			break;
			case 9 :
			PORTB = 0b01101111;
			break;
			
		}
	}
	
}

*/