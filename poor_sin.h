#ifndef POOR_SIN_H
#define POOR_SIN_H
#include <math.h>

#define PREC_TYPE double
#ifndef PI
  #define PI      3.1415926535
#endif
#ifndef HALF_PI
  #define HALF_PI 1.5707963267
#endif
#define HALF_FUNCTION 1
#define FMOD(x,y) _Generic((x), float: fmodf, double: fmod)(x, y)

PREC_TYPE psin(PREC_TYPE x){
  if(x < 0.0) x = (x * -1) + PI;
  int flip_y = ((int)(x / PI)) & 1;

#if HALF_FUNCTION
    int flip_x = ((int)(x / HALF_PI)) & 1;

    PREC_TYPE xmod = FMOD(x,HALF_PI);
    PREC_TYPE normalized = (xmod / HALF_PI) + flip_x;

    return flip_y ?
      ((normalized-1) * (normalized-1) * 1.02) - 1 :
      (((normalized-1) * (normalized-1)) * -1.02) + 1
      ;
#else
  PREC_TYPE xmod = FMOD(x,PI);
  if(PI - xmod < 0.0005 || xmod < 0.002){ return 0.0; }

  return flip_y ?
         ((xmod - 1.5707) * (xmod - 1.5707)) * 0.404 - 1 :
         ((xmod - 1.5707) * (xmod - 1.5707)) * -0.404 + 1 ;
#endif

}

#undef HALF_FUNCTION

PREC_TYPE pcos(PREC_TYPE x){
  return psin(x + HALF_PI);
}

#undef PREC_TYPE
#undef PI
#undef HALF_PI

#endif //POOR_SIN_H