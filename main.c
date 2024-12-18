#include "headers\InterfaceWindow.h"

int main(void){
    InitWindow(WIDHT_RES, HEIGHT_RES, "Killer OSU!");
    SetTargetFPS(240);
    Image icon = LoadImage("modeles/target_icon_264154.png");
    SetWindowIcon(icon);

    InitAudioDevice();

    Sound actionClick = LoadSound("modeles/soft-hitnormal.wav");
    Sound nonAction = LoadSound("modeles/sectionfail.wav");

    Color bgColor = GRAY;
    Vector2 mouse;
    Image img_circle = initTextureCircle();
    // Image appr = LoadImage("modeles/approachcircle.png");
    NewCircle *temp = initCircle(img_circle);

    Image cur = initImageCursor();
    Texture2D frame = LoadTextureFromImage(cur);
    Button btn = {{400, 400, 150, 50}};

    double TimeToStart = 3.0;
    unsigned int total = 0, misstakes = 0;

    HideCursor();
    bool start_flag = false;

    while(!WindowShouldClose()){
        mouse = GetMousePosition();
        if(CheckCollisionPointRec(mouse, btn.rec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            start_flag = true;
        }
        if(start_flag) TimeToStart -= GetFrameTime();

        if(start_flag && TimeToStart <= 0){
            bool click = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
            if(CheckCollisionPointCircle(mouse, temp->center, temp->frame.width / 2.0f - 5) && click){
                PlaySound(actionClick);
                total++;
                UnloadTexture(temp->frame);
                // UnloadTexture(temp->approach);
                free(temp);
                temp = initCircle(img_circle);
                click = false;
            }

            if(!CheckCollisionPointCircle(mouse, temp->center, temp->frame.width / 2.0f - 5) && click){
                PlaySound(nonAction);
                misstakes++;
                UnloadTexture(temp->frame);
                // UnloadTexture(temp->approach);
                free(temp);
                temp = initCircle(img_circle);
                click = false;
            }

            if(temp->lifetime.timeLife <= 0){
                PlaySound(nonAction);
                misstakes++;
                UnloadTexture(temp->frame);
                // UnloadTexture(temp->approach);
                free(temp);
                temp = initCircle(img_circle);
            }
            
            temp->lifetime.timeLife -= GetFrameTime();
            // if (temp->lifetime.timeLife > 0 && temp->frame.width <= temp->approach.height && temp->frame.height <= temp->approach.height){
            //     temp->approach.height -= GetFrameTime() / 2.0f;
            //     temp->approach.width -= GetFrameTime() / 2.0f;
            // }
        }
        BeginDrawing();
            ClearBackground(bgColor);
            if(!start_flag) MenuWindow(bgColor, btn, frame, mouse);
            if(start_flag) PlaygroundWindow(frame, *temp, mouse, total, misstakes, TimeToStart);
        EndDrawing();

    }
    UnloadImage(icon);
    // UnloadImage(appr);
    UnloadImage(cur);
    UnloadImage(img_circle);
    UnloadSound(actionClick);
    UnloadSound(nonAction);
    UnloadTexture(frame);
    // UnloadTexture(temp->approach);
    UnloadTexture(temp->frame);
    free(temp);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}