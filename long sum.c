#include<stdio.h>
#include<cs50.h>
int main(void){
long num1=get_long("please, enter your first number here:");
long num2= get_long("please, enter your second number here:");
long result= num1+num2;
printf("%li\n",result);
}
