
#include<stdio.h>
#include<cs50.h>
int main(void){
 int age= get_int("enter your age in years:");
 int leap_years=age/4;
 int days=(age*365)+leap_years;
 printf("you are approximately %i days old (including leap years).\n", days);
}
