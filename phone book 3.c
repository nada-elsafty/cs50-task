#include <stdio.h>
#include <cs50.h>
#include <string.h>
struct phonebook {
string names;
string numbers;
int age;
};
int main (void){
struct phonebook people [2] ;
people [0] . names = "nada";
people [0] . numbers = "012456";
people [0] . age = 25;
people [1] . names = "moody";
people [1] . numbers = "0125588";
people [1] . age = 36;
  for (int i=0 ; i <2 ; i++){
    if (strcmp (people [i] . names , "nada") ==0){
      printf (" found %s %d \n ", people [i] . numbers, people [i] . age);
      return 0;
    }
  }
  printf ("not found \n ");
  return 1;
}
