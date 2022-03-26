#include<stdio.h>
#include<math.h>
#include "code_func.h"


int main(){
      
    char choice='N';
    int n;

    printf( "\n\t\t\tElectrical Calculator\n\t" );
    printf( "\t\t---------------------\n\n" );

    do{
        
        printf( "\t1.Resistor COLOR Code Calculator\n" );
        printf( "\t2.Ohms law Calculator\n" );
        printf( "\t3.LED Series Resistor Calculator\n" );
        printf( "\t4.Battery Life Calculator\n\n" );
        printf( "\tPlease enter the mode number to operate:" );
        scanf("%d",&n);

        if(n==1){
            resistor_code();
        }else if(n==2){
            ohms_law();
        }else if(n==3){
            LED_series();
        }else if(n==4){
            battery_life();
        }else{
            printf("\tWrong Entry..bye...bye\n");
            break;
        }
        getchar();
        printf( "Do you want to continue(Y/N):");
        scanf("%c",&choice);
        
    }while(choice=='Y'); 
}