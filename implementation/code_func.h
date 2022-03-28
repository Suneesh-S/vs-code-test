
void resistor_code_print();
void ohms_law_print();
void LED_series_print();
void battery_life_print();

/////////////////////////////////////////////

typedef struct resistor Struct1;
Struct1 resistor_code_calc(int,char []);
float* ohms_law_calc(float []);
typedef struct LED Struct;
Struct LED_calc(double,double,double);
float bat_life_calc(float,float);

/////////////////////////////////////////////

void    print_codes( void );   
double  decode_char( char  );
double  tolerance_char( char  );
double ppm_char( char  );