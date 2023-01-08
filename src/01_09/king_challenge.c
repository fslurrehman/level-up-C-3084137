#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

enum movement
{
  NONE = 0,
  LEFT,
  RIGHT,
  UP,
  DOWN,
  RIGHT_UP,
  LEFT_UP,
  RIGHT_DOWN,
  LEFT_DOWN
};
#define MaxMovement 9

typedef struct position
{
  int x;
  int y;
}position;

position do_move(enum movement move, position pos){
  position r_pos;
  r_pos.x = pos.x;
  r_pos.y = pos.y;
  if (move == LEFT)
   r_pos.x = pos.x - 1;
  else if (move == RIGHT)
   r_pos.x = pos.x + 1;
  else if (move == UP)
   r_pos.y = pos.y - 1;
  else if (move == DOWN)
   r_pos.y = pos.y + 1;
  else if (move == RIGHT_UP){
   r_pos.x = pos.x + 1;
   r_pos.y = pos.y - 1;
  }
  else if (move == LEFT_UP){
   r_pos.x = pos.x - 1;
   r_pos.y = pos.y - 1;
  }
  else if (move == RIGHT_DOWN){
   r_pos.x = pos.x + 1;
   r_pos.y = pos.y + 1;
  }else if (move == LEFT_DOWN)
   {
     r_pos.x = pos.x - 1;
     r_pos.y = pos.y + 1;
   }
  return r_pos;
}

bool isout(position pos){
  if (pos.x == 0 || pos.x == 9)
   return true;
  else if (pos.y == 0 || pos.y == 9)
   return true;
  else 
   return false;
}

int print_pos(position pos){
  int i,j = 0;
  for (i = 1; i <= 8; i++){
    for (j = 1; j <= 8; j++){
      if(pos.x == j && pos.y == i){
        printf("K ");
      }
      else{
        printf(". ");
        }
    }
      printf("\n");
  }
}

int main(){
  position king_pos;
  king_pos.x = 5;
  king_pos.y = 4;
  int count = 0;
  enum movement r = NONE;
  printf("Position for Count %d:\n",count);
  printf("Move [0 - 9] is %d\nking position is (%d,%d)\n", r, king_pos.x, king_pos.y);
  print_pos(king_pos);

  srand((unsigned)time(NULL));


  while (1)
  {
   r = rand() % MaxMovement;
   king_pos = do_move(r, king_pos);
   count++;

   printf("Position for Count %d:\n", count);
   printf("Move [0 - 9] is %d\nking position is (%d,%d)\n", r, king_pos.x, king_pos.y);
   print_pos(king_pos);

   if (isout(king_pos)){
        printf("Maximum movement count is %d\n", count);
        break;
   }
  }
  return 0;
}