#include<stdio.h>

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
   printf( "\tNo colour---------------> X\n" );
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