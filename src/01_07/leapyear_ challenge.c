#include <stdio.h>
int leapyear(int year){
  if (year % 4 == 0)
   return 1;
  else if (year % 100 == 0)
   return 0;
  else if (year % 400 == 0)
   return 1;
  else
   return 0;
}

int main(){
  int year;
  for (year = 1582; year <= 2101; year++){
    if (leapyear(year))
     printf("%d\n", year);
  }

}