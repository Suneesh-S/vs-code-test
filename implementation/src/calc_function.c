#include<stdio.h>
#include<math.h>
#include "res_switch_case.h"

//////////////////////////////////////////////////////////////////////////////////////////////
/*calculator function*/
//////////////////////////////////////////////////////////////////////////////////////////////

double result[4]={0};
double* resistor_code_calc(int N,char code[]){
     
     double color[10];
     int num=0,multiplier,flag=0;
     double resistance=0;

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

      result[0]=resistance;
      result[3]=flag;
      if(N==6){
          result[1]=color[N-2];
          result[2]=color[N-1];
      }else{
          result[1]=color[N-1];
      }

      return result;
}

float* ohms_law_calc(float value[]){
     
    
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

    return value;
}

double* LED_calc(double Vs,double Vf,double If,double* res){
  
  double R,P;
  
  double *ans1,*ans2;
  ans1=&R;
  ans2=&P;

    *ans1=(Vs-Vf)/If;
    *ans2=(Vs-Vf)*If;
     res[0]=R;
     res[1]=P;

    return res;
}

float bat_life_calc(float mAh,float mA){

   float life;
   life=mAh/mA;

   return life;
}