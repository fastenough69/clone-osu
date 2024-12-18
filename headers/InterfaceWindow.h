#ifndef INTERFACEWINDOW_H_
#define INTERFACEWINDOW_H_

#include "circle_obj.h"

typedef struct {
    Rectangle rec;
} Button;

typedef struct {
    Texture2D frame;
    Vector2 crd;
    Color cl;
}NewButton;

void MenuWindow(Color bgColor, Button btn, Texture2D frame, Vector2 mouse);
void PlaygroundWindow(Texture2D frame, NewCircle temp, Vector2 mouse, int total, int misstakes, double StartTime);

#endif