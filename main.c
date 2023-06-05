#include <stdio.h>

#include "poor_sin.h"

int main() {
  double max_error = 0;
  for(double t = -5000; t < 5000.0; t += 0.1){
    double error = 0;
    double x = sin(t);
    double y = psin(t);
//    printf("%g|%g\n",x,y);
    error = fabs(x - y);
    if(error > max_error){
      max_error = error;
    }
  }
  printf("error: %g\n", max_error );
  return 0;
}

