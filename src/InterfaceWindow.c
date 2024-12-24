#include "../headers/InterfaceWindow.h"

void MenuWindow(Color bgColor, NewButton btn, Texture2D frame, Vector2 mouse){
    // DrawRectangle(btn.rec.x, btn.rec.y, btn.rec.width, btn.rec.height, btn.cl);
    DrawTexture(btn.frame, btn.crd.x, btn.crd.y, btn.cl);
    DrawTexture(frame, mouse.x - frame.width / 2.0f, mouse.y - frame.height / 2.0f, RAYWHITE);
}

void PlaygroundWindow(Texture2D frame, NewCircle temp, Vector2 mouse, int total, int misstakes, double StartTime){
    if(StartTime > 0){
        DrawText(TextFormat("%.1lf", StartTime), 100, 200, 20, BLACK);
    }
    // DrawCircleLines((int)temp.center.x, (int)temp.center.y, temp.frame.width / 2.0f - 5, GREEN);
    // DrawTexture(temp.approach, temp.center.x - temp.approach.width / 2.0f, temp.center.y - temp.approach.height / 2.0f, temp.cl);
    DrawTexture(temp.frame, temp.center.x - temp.frame.width / 2.0f, temp.center.y - temp.frame.height / 2.0f, temp.cl);
    DrawText(TextFormat("Current FPS: %d", GetFPS()), 100, 100, 20, BLACK);
    DrawText(TextFormat("Total: %d", total), 900, 700, 20, BLACK);
    DrawText(TextFormat("Mistakes: %d", misstakes), 850, 600, 20, BLACK);
    DrawTexture(frame, mouse.x - frame.width / 2.0f, mouse.y - frame.height / 2.0f, RAYWHITE);
}

NewButton *initButton(char *filename){
    NewButton *btn = malloc(sizeof(NewButton));
    btn->frame = LoadTexture(filename);
    btn->crd = (Vector2){WIDHT_RES / 2.0f - btn->frame.width / 2.0f, HEIGHT_RES / 2.0f - btn->frame.height / 2.0f};
    btn->cl = RAYWHITE;
    return btn;
}