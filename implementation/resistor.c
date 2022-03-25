#include <stdio.h>
#include <math.h>
#include "code_func.h"

int main()
{
     char    code[10];     /* one code per band */
     double  resistance;
     double  color[10];  /* decoded values */
     
     int     flag,N,num=0,multiplier;

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
   return 0;
}

    


/*   This function prints a menu of color codes to guide the user in
     entering input.                                               */

