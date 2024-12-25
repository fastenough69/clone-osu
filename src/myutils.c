#include "../headers/myutils.h"

// void UnloadAllAfterClose(){
// //     UnloadImage(icon);
// //     // UnloadImage(appr);
// //     UnloadImage(cur);
// //     UnloadImage(img_circle);
// //     UnloadTexture(new->frame);
// //     free(new);
// //     UnloadSound(actionClick);
// //     UnloadSound(nonAction);
// //     UnloadTexture(frame);
// //     // UnloadTexture(temp->approach);
// //     UnloadTexture(temp->frame);
// //     free(temp);
// //     CloseAudioDevice();
// //     CloseWindow();
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