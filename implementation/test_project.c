
#include "unity.h"
#include<stdio.h>
#include "calc_function.h"

void setUp(void)
{

}

void tearDown(void){

}

void test_ohms_law_calculator(){
   float value[]={4,0,2,0};
   float answer[]={4,2,2,8};
   
   TEST_ASSERT_EQUAL_INT8_ARRAY(answer,ohms_law_calc(value),4);
}
void test_battery_life_Calculator(){
    TEST_ASSERT_EQUAL(2.5,bat_life_calc(50,20));
}

void test_LED_series_calculator(){
    double answer[]={1,4};
    double value[]={0,0};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(answer,LED_calc(5,3,2,value),2);
}

void test_resistor_calculator(){
    double answer1[]={2400,0.25,0,0};
    char code1[]={'R','Y','R','E'};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(answer1,resistor_code_calc(4,code1),4);
    double answer2[]={242000000,0.25,0,0};
    char code2[]={'R','Y','R','E','E'};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(answer2,resistor_code_calc(5,code2),4);
    double answer3[]={274,5,5,0};
    char code3[]={'R','V','Y','B','U','V'};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(answer3,resistor_code_calc(6,code3),4);
}

int test_main(void){

    UnityBegin(NULL);

    RUN_TEST(test_resistor_calculator);
    RUN_TEST(test_ohms_law_calculator);
    RUN_TEST(test_LED_series_calculator);
    RUN_TEST(test_battery_life_Calculator);
    
    return(UnityEnd());
}




