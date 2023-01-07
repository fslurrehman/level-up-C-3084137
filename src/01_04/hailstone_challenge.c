#include <stdio.h>
#include <stdbool.h>

bool iseven(int i){
  if (i % 2 == 0){
    return true;
  }
  return false;
}

int main(){
  int n = 18;
  while (n != 1){
    printf("%d, ",n);
    if (iseven(n)){
      n = n/2;
    }else{
      n = (n*3) + 1;
    }
  }
  printf("%d.", n);
  return 0;
}