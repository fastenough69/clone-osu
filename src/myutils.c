#include "../headers/myutils.h"

// void ChangeMouseSpeed(float newValue, int flag){
//     int *curSpeed;
//     SystemParametersInfo(SPI_GETMOUSESPEED, 0, curSpeed, 0);
//     if(flag) SystemParametersInfo(SPI_GETMOUSESPEED, 0, &newValue, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
//     else SystemParametersInfo(SPI_GETMOUSESPEED, 0, curSpeed, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
// }

void ColSliders(Vector2 mouse, Slider *sld, float value){
    if(CheckCollisionPointCircle(mouse, sld->pos_circle, sld->rad_circle) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        sld->rec.width = mouse.x - sld->rec.x;
        sld->pos_circle.x = mouse.x;
        sld->value_pos.x = sld->pos_circle.x;
        sld->value = value;
        if(sld->rec.width < 50){
            sld->rec.width = 50;
            sld->pos_circle.x = sld->rec.x + 50;
        }
        if(sld->rec.width > sld->full_widht){
            sld->rec.width = sld->full_widht;
            sld->pos_circle.x = sld->rec.x + sld->full_widht;
        }
    }
}

bool II_logic(NewCircle temp, Slider sldTime){
    if(temp.lifetime.time <= (sldTime.value / 2.0f)){
        SetMousePosition(temp.center.x, temp.center.y);
        return true;
    }
    return false;
}