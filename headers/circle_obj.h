#ifndef CIRCLE_OBJ_H_
#define CIRCLE_OBJ_H_

// #include <windows.h>
#include "raylib.h"
#include <stdlib.h>
#include <stdint.h>
// #include <stdio.h>

#define WIDHT_RES GetMonitorWidth(0)
#define HEIGHT_RES GetMonitorHeight(0)
#define BASE_SIZE_CIRCLE 100

// #define FPS_APPROACH 0.5

typedef struct {
    float time;
}Timer;

typedef struct {
    Texture2D frame;
    // Texture2D approach;
    Vector2 center;
    Color cl;
    Timer lifetime;
}NewCircle;

int __myrand(const int cord1, const int cord2);
NewCircle *initCircle(Image img, float time);
Image initTextureCircle(int circle_r);
Image initImageCursor();

#endif