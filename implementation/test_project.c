
#include "unity.h"
#include<stdio.h>
#include "code_func.h"

void setUp(void)
{

}

void tearDown(void){

}

void test1(){
   float value[]={4,0,2,0};
   float answer[]={4,2,2,8};
   
   TEST_ASSERT_EQUAL_INT8_ARRAY(answer,ohms_law_calc(value),4);
}
void test2(){
    TEST_ASSERT_EQUAL(2.5,bat_life_calc(50,20));
}
void test3(){
    double answer[]={1,4};
    double value[]={0,0};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY(answer,LED_calc(5,3,2,value),2);
}

int main(void){

    UnityBegin(NULL);
    
    RUN_TEST(test1);
    RUN_TEST(test2);
    RUN_TEST(test3);
    return(UnityEnd());
}




