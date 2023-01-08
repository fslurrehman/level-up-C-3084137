#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* shuffle(char first_half[], char second_half[]){
  int i;
  int j = 0;
  //printf("%s and %s\n",first_half, second_half);
  //printf("%c%c%c\n\n", first_half[0], first_half[1], first_half[2]);
  //printf("%c%c%c\n\n", second_half[0], second_half[1], second_half[2]);

  char *r = malloc (sizeof(char) * (26 + 1));
  for (i = 0; i <= 12; i++){
    r[j] = first_half[i];
    r[j+1] = second_half[i];
    j +=2;
  }
  r[26]='\0';
  return r;
}
/*
bool ismatched(char* A, char* B){
  int i;
  bool r = true;
  for (i = 0;i <=25;i++){
    if(A[i] != B[i]){
      r = false;
      break;
    }
  }
  return r;
}
*/
/*
int print(char* arr){
  int i = 0;
  for (i = 0; i <=24; i++){
    printf("%c, ",arr[i]);

  }
  printf("%c, \n", arr[25]);
}
*/

int main(){
  char first_half[14] = "ABCDEFGHIJKLM";
  char second_half[14] = "NOPQRSTUVWXYZ";
  char *ordered = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  printf("First Half is: %s\nSecond Half is: %s\nOrdered List is: %s\n", 
          first_half, second_half, ordered);
  //printf("%c%c%c\n\n", first_half[0], first_half[1], first_half[2]);
  //printf("%c%c%c\n\n", second_half[0], second_half[1], second_half[2]);
  
  int count = 0;
  bool matched = false;
  
  while (matched == false){
    char* total = shuffle(first_half, second_half);
    int i = 0;
    for (i = 0; i <=12; i++){
      first_half[i] = total[i];
      second_half[i] = total[i+13];
    }
    //printf("new first half is: %s\n", first_half);
    //printf("new second half is: %s\n", second_half);
    count ++;
    printf("shuffled is: %s for count of %d\n", total, count);
    matched = true;
    for(i = 0;i<=25;i++){
      if (total[i] != ordered[i]){
        matched = false;
        break;
      }
    }
  }
  printf("shuffle is finally matched for final count of %d\n", count);

  /*
  //testing the check
  char* txt1 = "ABC";
  printf("%s\n",txt1);
  printf("%c\n", txt1[0]);
  printf("%c\n", txt1[1]);
  printf("%c\n", txt1[2]);
  if (txt1[0] == 'A')
   printf("matched: %c == %c\n\n",txt1[0],'A');
 */
  return 0;
}