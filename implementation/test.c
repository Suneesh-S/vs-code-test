#include<stdio.h>
#include<math.h>

int main(){
    float V=0,I=0,R=0,P=0;
    int x=0;
    char param[][50]={"Voltage","Current","Resistance","Power"};
    float arr[4]={0};

    printf("enter the 1st parameter:");
    scanf("%d",&x);
    printf("enter the value:");
    scanf("%f",&arr[x-1]);

    printf("enter the 2nd parameter:");
    scanf("%d",&x);
    printf("enter the value:");
    scanf("%f",&arr[x-1]);
    
    if(arr[1]==0 && arr[0]==0){
        arr[0]=sqrt(arr[2]*arr[3]);
        arr[1]=sqrt(arr[3]/arr[2]);
    }else if (arr[2]==0 && arr[3]==0)
    {
        arr[2]=arr[0]/arr[1];
        arr[3]=arr[0]*arr[1];
    }else if(arr[0]==0 && arr[2]==0)
    {
        arr[0]=arr[3]/arr[1];
        arr[2]=arr[3]/(pow(arr[1],2));
    }else if(arr[0]==0 && arr[3]==0)
    {
        arr[0]=arr[1]*arr[2];
        arr[3]=pow(arr[1],2)*arr[2];
    }else if(arr[1]==0 && arr[2]==0)
    {
        arr[1]=arr[3]/arr[0];
        arr[2]=pow(arr[0],2)/arr[3];
    }else if(arr[1]==0 && arr[3]==0)
    {
        arr[1]=arr[0]/arr[2];
        arr[3]=pow(arr[0],2)/arr[2];
    }
    
    printf("the values are:\n");
    for(int i=0;i<4;i++){
        printf("%s is %f \n",param[i],arr[i]);
    }
    
}