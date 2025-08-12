
#include<stdio.h>
#include<cs50.h>
int main(void){
 int age= get_int("enter your age in years:");
 int months= age*12;
 printf("you are approximately %i months old.\n", months);
}
