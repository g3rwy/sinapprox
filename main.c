#include <stdio.h>

#include "poor_sin.h"

#ifdef USE_RAYLIB
#include "raylib.h"

float lerp(float a, float b, float f) {
  return a + f * (b - a);
}
const int WIDTH = 1080;
const int HEIGHT = 720;

int main(){
  InitWindow(WIDTH, HEIGHT, "Testing my approximation of sin/cos");
  float x = PI, y = PI;
  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawCircle(psin(x) * 100 + (1080/2),pcos(y) * 100 + (720/2),50.0f,RED);
    DrawCircle(psin(x - 3.14) * 100 + (1080/2),pcos(y-3.14) * 100 + (720/2),50.0f,PURPLE);
    x += GetFrameTime();
    y += GetFrameTime();

    if(x > PI * 4) {
      x -= PI * 4;
      y -= PI * 4;
    }

    for(int i = 0; i <= 300; i++) {
      DrawPixel(i + 600,psin(-lerp( -(PI/2), 1.5f * PI, (float)i / 300.f)) * 80.0 + 200 , GREEN);
      DrawPixel(i + 600,psin(-lerp( -(PI/2), 1.5f * PI, (float)i / 300.f)) * 80.0 + 201 , GREEN);
    }
    EndDrawing();
  }

  CloseWindow();

  return 0;
}


#else
int main() {
  double max_error = 0.0f;
  for(double t = -5000.0f; t < 5000.0f; t += 0.1f){
    double error = 0.0f;
    double x = sin(t);
    double y = psin(t);
    error = fabs(x - y);
    if(error > max_error){
      max_error = error;
    }
  }
  printf("error: %g\n", max_error );
  return 0;
}
#endif

