#ifndef INTERFACEWINDOW_H_
#define INTERFACEWINDOW_H_

#include "circle_obj.h"

typedef struct {
    Texture2D frame;
    Vector2 crd;
    Color cl;
}NewButton;

typedef struct {
    Rectangle rec;
    float full_widht;
    float r;
    Color cl;
    Vector2 text_info_pos;
    char *text_info;
    Vector2 value_pos;
    float value;
    Vector2 pos_circle;
    float rad_circle;
} Slider;

void MenuWindow(Color bgColor, NewButton btn, Texture2D frame, Vector2 mouse, Slider sldTime, Slider sldSize, Slider sldSens);
void PlaygroundWindow(Texture2D frame, NewCircle temp, Vector2 mouse, int total, int misstakes, double StartTime, NewButton repeat);
NewButton *initButton(char *filename);
Slider *initSlider(char *text, float cord_y);
void DrawSlider(Slider sld);

#endif