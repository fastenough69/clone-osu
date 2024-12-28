#include "../headers/InterfaceWindow.h"

void MenuWindow(Color bgColor, NewButton btn, Texture2D frame, Vector2 mouse, Slider sldTime, Slider sldSize, Slider sldSens){
    // DrawRectangle(btn.rec.x, btn.rec.y, btn.rec.width, btn.rec.height, btn.cl);
    DrawTexture(btn.frame, btn.crd.x, btn.crd.y, btn.cl);
    DrawSlider(sldTime);
    DrawSlider(sldSize);
    DrawSlider(sldSens);
    DrawTexture(frame, mouse.x - frame.width / 2.0f, mouse.y - frame.height / 2.0f, RAYWHITE);
}

void PlaygroundWindow(Texture2D frame, NewCircle temp, Vector2 mouse, int total, int misstakes, double StartTime, NewButton repeat){
    if(StartTime > 0){
        DrawText(TextFormat("%.1lf", StartTime), 100, 200, 20, BLACK);
    }
    DrawTexture(repeat.frame, repeat.crd.x, repeat.crd.y, repeat.cl);
    // DrawCircleLines((int)temp.center.x, (int)temp.center.y, temp.frame.width / 2.0f - 5, GREEN);
    // DrawTexture(temp.approach, temp.center.x - temp.approach.width / 2.0f, temp.center.y - temp.approach.height / 2.0f, temp.cl);
    DrawTexture(temp.frame, temp.center.x - temp.frame.width / 2.0f, temp.center.y - temp.frame.height / 2.0f, temp.cl);
    DrawText(TextFormat("Current FPS: %d", GetFPS()), 100, 100, 20, BLACK);
    DrawText(TextFormat("x%d", total), WIDHT_RES - 300, HEIGHT_RES - 100, 20, BLACK);
    DrawText(TextFormat("Total: %d", misstakes), WIDHT_RES - 300, HEIGHT_RES - 200, 20, BLACK);
    DrawTexture(frame, mouse.x - frame.width / 2.0f, mouse.y - frame.height / 2.0f, RAYWHITE);
}

NewButton *initButton(char *filename){
    NewButton *btn = malloc(sizeof(NewButton));
    btn->frame = LoadTexture(filename);
    btn->crd = (Vector2){WIDHT_RES / 2.0f - btn->frame.width / 2.0f, HEIGHT_RES / 2.0f - btn->frame.height / 2.0f};
    btn->cl = RAYWHITE;
    return btn;
}

Slider *initSlider(char *text, float cord_y){
    Slider *sld = malloc(sizeof(Slider));
    sld->full_widht = 300;
    sld->rec = (Rectangle){WIDHT_RES / 2.0f - sld->full_widht / 2.0f, HEIGHT_RES / 2.0f + cord_y, 100, 5};
    sld->r = 1.0;
    sld->cl = RED;
    sld->text_info_pos = (Vector2){sld->rec.x + sld->full_widht + 10, sld->rec.y};
    sld->text_info = text;
    sld->rad_circle = 10.0;
    sld->pos_circle = (Vector2){sld->rec.x + sld->rec.width, sld->rec.y + sld->rad_circle / 2.0f};
    sld->value_pos = (Vector2){sld->pos_circle.x, sld->pos_circle.y + 10};
    sld->value = 0;
    return sld;
}

void DrawSlider(Slider sld){
    DrawRectangleRounded((Rectangle){sld.rec.x, sld.rec.y, sld.full_widht, sld.rec.height}, sld.r, 5, RAYWHITE);
    DrawRectangleRounded(sld.rec, sld.r, 5, sld.cl);
    DrawCircle(sld.pos_circle.x, sld.pos_circle.y, sld.rad_circle, (Color){255, 153, 153, 255});
    DrawText(TextFormat("%.1f", sld.value), sld.value_pos.x, sld.value_pos.y, 17, BLACK);
    DrawText(sld.text_info, sld.text_info_pos.x, sld.text_info_pos.y, 17, BLACK);
}