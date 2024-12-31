#ifndef MYUTILS_H_
#define MYUTILS_H_

#include "circle_obj.h"
#include "InterfaceWindow.h"

// void UnloadAllAfterClose();
void ChangeMouseSpeed(float newValue, int flag);
void ColSliders(Vector2 mouse, Slider *sld, float value);
bool II_logic(NewCircle temp, Slider sldTime);
#endif