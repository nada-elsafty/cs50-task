
#include<stdio.h>
#include<cs50.h>
int main(void){
 int age= get_int("enter your age in years:");
 int days= age*365;
 printf("you are approximately %i days old.\n", days);
}
