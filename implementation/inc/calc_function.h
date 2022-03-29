#ifndef __CALC_FUNCTION_H
#define __CALC_FUNCTION_H

double* resistor_code_calc(int,char []);
float* ohms_law_calc(float []);
double* LED_calc(double,double,double,double*);
float bat_life_calc(float,float);


#endif


/////gcc calc_main.c test_project.c src/calc_function.c src/print_function.c src/res_switch_case.c unity/unity.c -Iunity -Isrc -lm