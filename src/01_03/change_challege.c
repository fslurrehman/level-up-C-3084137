#include <stdio.h>

int quarter(double dollar){
  int r = (int) (dollar * 4);
  return r;
}

int dime(double dollar){
  int r = (int) (dollar * 10);
  return r;
}

int nickel(double dollar){
  int r = (int) (dollar * 20);
  return r;
}
double round(double var)
{
  // 37.66666 * 100 =3766.66
  // 3766.66 + .5 =3767.16    for rounding off value
  // then type cast to int so value is 3767
  // then divided by 100 so the value converted into 37.67
  double value = (int)(var * 100 + .5);
  return (double)value / 100;
}

int penny(double dollar){
  //printf("before casting: %.3f\n",dollar*100);
  int r = (int) round((dollar * 100));
  //printf("after casting %d\n", r);
  return r;
}


int main(){
  double dol[] = {0.49, 1.27, 0.75, 1.31, 0.83};

  for (int i = 0; i <= 4; i++)
  {
    int q, d, n, p = 0;
    q = quarter(dol[i]);
    if (dime(dol[i] - ((double) q)/4) >= 0)
        d = dime(dol[i] - ((double) q)/4);
    if (nickel(dol[i] - ((double) q)/4 - ((double) d)/10) >= 0)
        n = nickel(dol[i] - ((double) q) / 4 - ((double) d) / 10);
    if (penny(dol[i] - ((double) q) / 4 - ((double) d) / 10 - ((double) n) / 20) >= 0)
        p = penny(dol[i] - ((double) q) / 4 - ((double) d) / 10 - ((double) n) / 20);
    printf("$ %0.2f is equal to %d quarters, %d dimes, %d nickels and %d pennies. \n",
            dol[i], q, d, n, p);
  }
  return 0;


}
