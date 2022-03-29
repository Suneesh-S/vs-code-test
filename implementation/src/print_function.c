#include<stdio.h>
#include<math.h>
#include "inc/print_function.h"
#include "inc/calc_function.h"


/////////////////////////////////////
/* printing function*/
////////////////////////////////////

void resistor_code_print()
{
     char    code[10];     /* one code per band */
     double  color[10];  /* decoded values */
     int     N;
     double* ans;

     /* Print codes and prompt for user input. */
     print_codes();
     printf( "\n\n\tEnter no of colour Bands(4 or 5 or 6): " );
     scanf("%d",&N);
     getchar();
     printf( "\n\n\tEnter the colour Bands:" );
     /* Read three character codes. */
     for(int i=0;i<N;i++){
         code[i]=getchar();
     }

     /* Decode each character code. */
     ans=resistor_code_calc(N,code);
     
     if(ans[3]==0){
         if(N==6){
            printf( "\n\n\tResistance in ohms:\t%.2f tolerance %.2f %% %.1f ppm \n", ans[0],ans[1],ans[1] );
         }else{
          printf( "\n\n\tResistance in ohms:\t%.2f tolerance %.2f %% \n", ans[0],ans[1] );  
         }
       
     }
   
}

void ohms_law_print(){
    float V=0,I=0,R=0,P=0;
    int x=0;
    char param[][50]={"Voltage","Current","Resistance","Power"};
    char unit[][10]={"V","A","Ohms","W"};
    float value[4]={0};

    printf("Please enter any two parameter\n");
    printf("1.Voltage\n2.Current\n3.Resistance\n4.Power\n");

    printf("enter the 1st parameter serial number:");
    scanf("%d",&x);
    printf("enter the %s value in %s:",param[x-1],unit[x-1]);
    scanf("%f",&value[x-1]);

    printf("enter the 2nd parameter serial number:");
    scanf("%d",&x);
    printf("enter the %s value in %s:",param[x-1],unit[x-1]);
    scanf("%f",&value[x-1]);
    
    float* value1;
    value1=ohms_law_calc(value);
    
    printf("\nthe values are:\n\n");
    for(int i=0;i<4;i++){
        printf("%s is %.2f%s\n",param[i],value1[i],unit[i]);
    }
    
}

void LED_series_print(){
    double Vs,Vf,If;
    double res[2]={0};
    double* result;
    printf("Use this tool to calculate resistance to drive series connected LED...\n");
    printf("Enter the Supply Voltage:");
    scanf("%lf",&Vs);
    printf("Enter the Forward Voltage:");
    scanf("%lf",&Vf);
    printf("Enter the Forward Current:");
    scanf("%lf",&If);

    result=LED_calc(Vs,Vf,If,res);
    printf("The series Resistance value for LED is:%.2lfK ohms\n",result[0]);
    printf("The Power value for LED is:%.3lfmW\n",result[1]);
}

void battery_life_print(){
    float mAh,mA;
    float life;
    printf("Enter the Battery Capacity(mAh):");
    scanf("%f",&mAh);
    printf("Enter the Device Consumption(mA):");
    scanf("%f",&mA);
    
    life=bat_life_calc(mAh,mA);
    int x=life;
    float min=(life-x)*60;
    int hour=(int)life;
    printf("the battery life in hours is:%d hours %.1f minutes\n",hour,min);
}


