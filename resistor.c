#include <stdio.h>
#include <math.h>

void    print_codes( void );     /* menu of codes */
double  decode_char( char  );
double  tolerance_char( char  );
double ppm_char( char  );

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

void  print_codes( void )
{
   printf( "\n\n\tThe colored bands are coded as follows:\n\n\n\t" );
   printf( "COLOR\t\t\tCODE\n\t" );
   printf( "-----\t\t\t----\n\n" );
   printf( "\tBlack-------------------> B\n" );
   printf( "\tBrown-------------------> N\n" );
   printf( "\tRed---------------------> R\n" );
   printf( "\tOrange------------------> O\n" );
   printf( "\tYellow------------------> Y\n" );
   printf( "\tGreen-------------------> G\n" );
   printf( "\tBlue--------------------> E\n" );
   printf( "\tViolet------------------> V\n" );
   printf( "\tGrey--------------------> A\n" );
   printf( "\tWhite-------------------> W\n" );
   printf( "\tGold--------------------> U\n" );
   printf( "\tSilver------------------> Z\n" );
}



double decode_char( char c )
{   
     switch ( c ) {
     case 'B':
          return 0.0;
     case 'N':
          return 1.0;
     case 'R':
          return 2.0;
     case 'O':
          return 3.0;
     case 'Y':
          return 4.0;
     case 'G':
          return 5.0;
     case 'E':
          return 6.0;
     case 'V':
          return 7.0;
     case 'A':
          return 8.0;
     case 'W':
          return 9.0;
     default:
          return -1;     /* illegal code */
     }

     
}

double tolerance_char( char c )
{   
     switch ( c ) {
     case 'N':
          return 1.0;
     case 'R':
          return 2.0;
     case 'G':
          return 0.5;
     case 'E':
          return 0.25;
     case 'V':
          return 0.1;
     case 'A':
          return 0.05;
     case 'X':
          return 20.0;
     case 'U':
          return 5.0;
     case 'Z':
          return 10.0;
     default:
          return -1;     /* illegal code */
     }
}

double ppm_char( char c )
{   
     switch ( c ) {
     case 'N':
          return 100;
     case 'R':
          return 50;
     case 'O':
          return 15;
     case 'Y':
          return 25;
     case 'E':
          return 10;
     case 'V':
          return 5;
     
     default:
          return -1;     /* illegal code */
     }
}