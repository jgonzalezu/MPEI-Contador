/*
 * File:   LedOn.c
 * Author: Juan Gonzalez
 *
 * Created on 20 de septiembre de 2020, 18:21
 */


#include "reloj.h"
#include "config.h"
#include <libpic30.h> // Incluye varias librerias �tiles de C

void num(int dig){
    
    switch(dig){
        
        case 0:
            PORTBbits.RB0=1;
            PORTBbits.RB1=1;
            PORTBbits.RB2=1;
            PORTBbits.RB3=1;
            PORTBbits.RB4=1;
            PORTBbits.RB5=1;
            PORTBbits.RB6=0;
            break;
            
        case 1:
            PORTBbits.RB0=0;
            PORTBbits.RB1=1;
            PORTBbits.RB2=1;
            PORTBbits.RB3=0;
            PORTBbits.RB4=0;
            PORTBbits.RB5=0;
            PORTBbits.RB6=0;
            break;
            
        case 2:
            PORTBbits.RB0=1;
            PORTBbits.RB1=1;
            PORTBbits.RB2=0;
            PORTBbits.RB3=1;
            PORTBbits.RB4=1;
            PORTBbits.RB5=0;
            PORTBbits.RB6=1;
            break;
            
        case 3:
            PORTBbits.RB0=1;
            PORTBbits.RB1=1;
            PORTBbits.RB2=1;
            PORTBbits.RB3=1;
            PORTBbits.RB4=0;
            PORTBbits.RB5=0;
            PORTBbits.RB6=1;
            break;
            
        case 4:
            PORTBbits.RB0=0;
            PORTBbits.RB1=1;
            PORTBbits.RB2=1;
            PORTBbits.RB3=0;
            PORTBbits.RB4=0;
            PORTBbits.RB5=1;
            PORTBbits.RB6=1;
            break;
            
        case 5:
            PORTBbits.RB0=1;
            PORTBbits.RB1=0;
            PORTBbits.RB2=1;
            PORTBbits.RB3=1;
            PORTBbits.RB4=0;
            PORTBbits.RB5=1;
            PORTBbits.RB6=1;
            break;
            
        case 6:
            PORTBbits.RB0=1;
            PORTBbits.RB1=0;
            PORTBbits.RB2=1;
            PORTBbits.RB3=1;
            PORTBbits.RB4=1;
            PORTBbits.RB5=1;
            PORTBbits.RB6=1;
            break;
            
        case 7:
            PORTBbits.RB0=1;
            PORTBbits.RB1=1;
            PORTBbits.RB2=1;
            PORTBbits.RB3=0;
            PORTBbits.RB4=0;
            PORTBbits.RB5=0;
            PORTBbits.RB6=0;
            break;
            
        case 8:
            PORTBbits.RB0=1;
            PORTBbits.RB1=1;
            PORTBbits.RB2=1;
            PORTBbits.RB3=1;
            PORTBbits.RB4=1;
            PORTBbits.RB5=1;
            PORTBbits.RB6=1;
            break;
            
        case 9:
            PORTBbits.RB0=1;
            PORTBbits.RB1=1;
            PORTBbits.RB2=1;
            PORTBbits.RB3=1;
            PORTBbits.RB4=0;
            PORTBbits.RB5=1;
            PORTBbits.RB6=1;
            break;
    }
    

}

int pulsador(){
    int dir;
    dir = PORTBbits.RB9;
    return dir;
}

int main(void) {
    
    AD1PCFG=0xFFFF;//todo como digital 
    
    TRISBbits.TRISB0 = 0; // A
    TRISBbits.TRISB1 = 0; // B
    TRISBbits.TRISB2 = 0; // C
    TRISBbits.TRISB3 = 0; // D
    TRISBbits.TRISB4 = 0; // E
    TRISBbits.TRISB5 = 0; // F
    TRISBbits.TRISB6 = 0; // G
    
    TRISBbits.TRISB8 = 0; // 1 DIGITO
    TRISBbits.TRISB7 = 0; // 2 DIGITO
    
    TRISBbits.TRISB9 = 1; // PULSADOR
      
    
    int tiempo = 30;
    int del = 1 ;
    while(1){
        
        int i,i1;
        int j,j1;
        int t;
        int dir;
        
        
        if (pulsador() == 0 ){
                i1 = 9;
            } else {
                i1 = 0;
            }
        
        for( i = i1 ; i < 10 & i >= 0; i = i){
            
            if (pulsador() == 0 ){
                j1 = 9;
            } else {
                j1 = 0;
            }
            
            for( j = j1 ; j < 10 & j >= 0; j = j){
                
              
                for(t = 0; t < tiempo; t++){

            
                    
                    PORTBbits.RB8 = 1;
                    PORTBbits.RB7 = 0;
                    num(i);

                    __delay_ms(del);
                    
                    PORTBbits.RB7 = 1;
                    PORTBbits.RB8 = 0;
                    num(j);

                    __delay_ms(del);
            
                }
                
                dir = pulsador();
                
                if (dir == 1){
                    j++;
                } else {
                    j--;
                    
                }
            }
            
            dir = pulsador();
            
            if (dir == 1){
                i++;
            } else {
                i--;
            }
        }
 
    }  
}