#include<stdio.h>
#include<math.h>

void resistor_code();
void ohms_law();

int main(){
      
    char choice='N';
    int n;

    printf( "Electrical Calculator\t" );
    printf( "---------------------\n\n" );
    do{
        
        printf( "1.Resistor COLOR Code Calculator" );
        printf( "2.Ohms law Calculator" );
        printf( "Please enter the mode number to operate:" );
        scanf("%d",&n);

        if(n==1){
            resistor_code();
        }else if(n==2){
            ohms_law();
        }

        printf( "Do you want to continue(Y/N):");
        scanf("%c",&choice);

    }while(choice=='Y'); 
}