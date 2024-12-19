#ifndef CIRCLE_OBJ_H_
#define CIRCLE_OBJ_H_

#include "raylib.h"
#include <stdlib.h>

#define WIDHT_RES 1000
#define HEIGHT_RES 800

// #define FPS_APPROACH 0.5

typedef struct {
    float timeLife;
}Timer;

typedef struct {
    Texture2D frame;
    // Texture2D approach;
    Vector2 center;
    Color cl;
    Timer lifetime;
}NewCircle;

int __myrand(const int cord1, const int cord2);
NewCircle *initCircle(Image img);
Image initTextureCircle();
Image initImageCursor();

#endif