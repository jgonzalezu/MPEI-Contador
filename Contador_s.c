/*
 * File:   Contador.c
 * Author: Juan Gonzalez
 *
 * Created on 23 de septiembre de 2020, 12:06
 */

#include "reloj.h"
#include "config.h"
#include <libpic30.h> // Incluye varias librerias útiles de C

void num(int dig){
    
    switch(dig){
        
        case 0:
            TRISBbits.TRISB0=0;
            TRISBbits.TRISB1=0;
            TRISBbits.TRISB2=0;
            TRISBbits.TRISB3=0;
            TRISBbits.TRISB13=0;
            TRISBbits.TRISB5=0;
            TRISBbits.TRISB7=1;
            break;
            
        case 1:
            
            
            TRISBbits.TRISB0 = 1; // A
            TRISBbits.TRISB1 = 0; // B
            TRISBbits.TRISB2 = 0; // C
            TRISBbits.TRISB3 = 1; // D
            TRISBbits.TRISB13 = 1; // E
            TRISBbits.TRISB5 = 1; // F
            TRISBbits.TRISB7 = 1; // G
            break;                    
            
        case 2:
            TRISBbits.TRISB0=0;
            TRISBbits.TRISB1=0;
            TRISBbits.TRISB2=1;
            TRISBbits.TRISB3=0;
            TRISBbits.TRISB13=0;
            TRISBbits.TRISB5=1;
            TRISBbits.TRISB7=0;
            break;
            
        case 3:
            TRISBbits.TRISB0=0;
            TRISBbits.TRISB1=0;
            TRISBbits.TRISB2=0;
            TRISBbits.TRISB3=0;
            TRISBbits.TRISB13=1;
            TRISBbits.TRISB5=1;
            TRISBbits.TRISB7=0;
            break;
            
        case 4:
            TRISBbits.TRISB0=1;
            TRISBbits.TRISB1=0;
            TRISBbits.TRISB2=0;
            TRISBbits.TRISB3=1;
            TRISBbits.TRISB13=1;
            TRISBbits.TRISB5=0;
            TRISBbits.TRISB7=0;
            break;
            
        case 5:
            TRISBbits.TRISB0=0;
            TRISBbits.TRISB1=1;
            TRISBbits.TRISB2=0;
            TRISBbits.TRISB3=0;
            TRISBbits.TRISB13=1;
            TRISBbits.TRISB5=0;
            TRISBbits.TRISB7=0;
            break;
            
        case 6:
            TRISBbits.TRISB0=0;
            TRISBbits.TRISB1=1;
            TRISBbits.TRISB2=0;
            TRISBbits.TRISB3=0;
            TRISBbits.TRISB13=0;
            TRISBbits.TRISB5=0;
            TRISBbits.TRISB7=0;
            break;
            
        case 7:
            TRISBbits.TRISB0=0;
            TRISBbits.TRISB1=0;
            TRISBbits.TRISB2=0;
            TRISBbits.TRISB3=1;
            TRISBbits.TRISB13=1;
            TRISBbits.TRISB5=1;
            TRISBbits.TRISB7=1;
            break;
            
        case 8:
            TRISBbits.TRISB0=0;
            TRISBbits.TRISB1=0;
            TRISBbits.TRISB2=0;
            TRISBbits.TRISB3=0;
            TRISBbits.TRISB13=0;
            TRISBbits.TRISB5=0;
            TRISBbits.TRISB7=0;
            break;
            
        case 9:
            TRISBbits.TRISB0=0;
            TRISBbits.TRISB1=0;
            TRISBbits.TRISB2=0;
            TRISBbits.TRISB3=0;
            TRISBbits.TRISB13=1;
            TRISBbits.TRISB5=0;
            TRISBbits.TRISB7=0;
            break;
        
        case 10:
            PORTBbits.RB0=1;
            PORTBbits.RB1=1;
            PORTBbits.RB2=1;
            PORTBbits.RB3=1;
            PORTBbits.RB13=1;
            PORTBbits.RB5=1;
            PORTBbits.RB7=1;
          
            break;
    }
    

}

int main(void) {
    
    AD1PCFG=0xFFFF;//todo como digital 
    
    TRISBbits.TRISB0 = 0; // A
    TRISBbits.TRISB1 = 0; // B
    TRISBbits.TRISB2 = 0; // C
    TRISBbits.TRISB3 = 0; // D
    TRISBbits.TRISB13 = 0; // E
    TRISBbits.TRISB5 = 0; // F
    TRISBbits.TRISB7 = 0; // G
    
    
    
    TRISBbits.TRISB8 = 0; // 1 DIGITO
    TRISBbits.TRISB9 = 0; // 2 DIGITO
    
     
    
    int tiempo = 1000000;
    while(1){
        

        int i;
        int j;
        int t;
        
        for(i = 0; i < 10; i++){
            
            for(j = 0; j < 10; j++){  
                
                for(t = 0; t < tiempo; t++){
                    
                    
                    
                    PORTBbits.RB9 = 0;
                    num(3);
                    __delay_ms(1)
                    PORTBbits.RB8 = 1;
                    num(3);
                    __delay_ms(1)
                    
                    PORTBbits.RB8 = 0;
                    num(8);
                    __delay_ms(1)
                    PORTBbits.RB9 = 1;
                    num(8);
                    __delay_ms(1)
                   
            
                }
            
            }                  
        }
 
    }  
}




