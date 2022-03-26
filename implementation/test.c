#include<stdio.h>
#include<math.h>
#include "code_func.h"

void resistor_code()
{
     char    code[10];     /* one code per band */
     double  resistance;
     double  color[10];  /* decoded values */
     
     int     flag=0,N,num=0,multiplier;

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
     if(N==6){
         for(int i=0;i<N-2;i++){
     color[i] = decode_char(code[i]);
    }
     color[N-2]=tolerance_char(code[N-2]);
     color[N-1]=ppm_char(code[N-1]);
     }else{
         for(int i=0;i<N-1;i++){
     color[i] = decode_char(code[i]);
    }
     color[N-1]=tolerance_char(code[N-1]);
     }

     /* Check whether codes were legal. */
     for(int i=0;i<N;i++){
         if(color[i]==-1){
           printf( "\n\n\tBad code -- cannot compute resistance\n" );
           flag=1;
           break;
         }
         if(N<6 && i<N-2){
              num=num*10+color[i];
         }else if(N==6 && i<N-3){
              num=num*10+color[i];
         }else if(N<6){
             multiplier=pow(10,color[N-2]);
             continue;
         }else{
              multiplier=pow(10,color[N-3]);
              continue;
         }
    }

      resistance=num*multiplier;
     if(flag==0){
         if(N==6){
            printf( "\n\n\tResistance in ohms:\t%.2f tolerance %.2f %% %.1f ppm \n", resistance,color[N-2],color[N-1] );
         }else{
          printf( "\n\n\tResistance in ohms:\t%.2f tolerance %.1f %% \n", resistance,color[N-1] );  
         }
       
     }
   
}



void ohms_law(){
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
    
    if(value[1]==0 && value[0]==0){
        value[0]=sqrt(value[2]*value[3]);
        value[1]=sqrt(value[3]/value[2]);
    }else if (value[2]==0 && value[3]==0)
    {
         value[2]=value[0]/value[1];
        value[3]=value[0]*value[1];
    }else if(value[0]==0 && value[2]==0)
    {
        value[0]=value[3]/value[1];
        value[2]=value[3]/(pow(value[1],2));
    }else if(value[0]==0 && value[3]==0)
    {
        value[0]=value[1]*value[2];
        value[3]=pow(value[1],2)*value[2];
    }else if(value[1]==0 && value[2]==0)
    {
        value[1]=value[3]/value[0];
        value[2]=pow(value[0],2)/value[3];
    }else if(value[1]==0 && value[3]==0)
    {
        value[1]=value[0]/value[2];
        value[3]=pow(value[0],2)/value[2];
    }
    
    printf("\nthe values are:\n\n");
    for(int i=0;i<4;i++){
        printf("%s is %.2f%s\n",param[i],value[i],unit[i]);
    }
    
}

void LED_series(){
    double R,Vs,Vf,If,P;
    double *ans1,*ans2;
    ans1=&R;
    ans2=&P;
    printf("Use this tool to calculate resistance to drive series connected LED...\n");
    printf("Enter the Supply Voltage:");
    scanf("%lf",&Vs);
    printf("Enter the Forward Voltage:");
    scanf("%lf",&Vf);
    printf("Enter the Forward Current:");
    scanf("%lf",&If);
  
    *ans1=(Vs-Vf)/If;
    *ans2=(Vs-Vf)*If;
    printf("The series Resistance value for LED is:%.3lfK ohms\n",R);
    printf("The Power value for LED is:%.3lfmW\n",P);
}

void battery_life(){
    float mAh,mA;
    float life;
    printf("Enter the Battery Capacity(mAh):");
    scanf("%f",&mAh);
    printf("Enter the Device Consumption(mA):");
    scanf("%f",&mA);
    life=mAh/mA;
    
    int x=life;
    float min=(life-x)*60;
    int hour=(int)life;
    printf("the battery life in hours is:%d hours %.1f minutes\n",hour,min);
}