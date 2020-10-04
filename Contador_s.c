/*
 * File:   Contador.c
 * Author: Juan Gonzalez
 *
 * Created on 23 de septiembre de 2020, 12:06
 */

#include "reloj.h"
#include "config.h"
#include <libpic30.h> // Incluye varias librerias útiles de C

int state = -1;

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

int pulsador(){
    int dir;
    int p1,p2,p3,p4;
    
    p1 = PORTBbits.RB14;
    __delay_ms(0.05)
    p2 = PORTBbits.RB14;
    __delay_ms(0.05)
    p3 = PORTBbits.RB14;
    __delay_ms(0.05)
    p4 = PORTBbits.RB14;
    
    if (p1+p2+p3+p4 == 4){
        state = state*-1;
        return 0;
    } else {
        if (state == -1){
            return 1;
        } else {
            return 0;
        }
    };
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
    
    TRISBbits.TRISB14 = 1; // Pulsador
    
     
    
    int tiempo = 50;
    int del = 1;
    
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
                
                    
                    PORTBbits.RB9 = 0;
                    __delay_ms(del)
                    PORTBbits.RB8 = 1;
                    num(i);
                    __delay_ms(del)
                    
                    PORTBbits.RB8 = 0;
                    __delay_ms(del)
                    PORTBbits.RB9 = 1;
                    num(j);
                    __delay_ms(del)
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