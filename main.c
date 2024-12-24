/*
    Нужено разобрраться с отностилеьными путям к файлам текстур. +
    Нужно сделать меню с текстурами и анимациями:
        -сделать кнопку старта ++
        -сделать возможность менять сложность:
            --изменять время жизни круга
            --изменять размер круга
        -сделать возможность создавать сколько времени будет идти раунд
        -*сделать возможность изменения чувствательности мыши
    Нужно сделать новый подсчет очков опираясь на сложность
    Нужно сделать разрешение динимичекое
    Нужно сделать возможность взаимодействия не только с кнопками мыши
    

*/

#include "headers/InterfaceWindow.h"

int main(void){
    InitWindow(WIDHT_RES, HEIGHT_RES, "Killer OSU!");
    SetTargetFPS(240);
    Image icon = LoadImage("modeles/target_icon_264154.png");
    SetWindowIcon(icon);
    InitAudioDevice();

    SetWindowSize(1920, 1080);

    // ToggleBorderlessWindowed();
    // ToggleFullscreen();

    Sound actionClick = LoadSound("modeles/soft-hitnormal.wav");
    Sound nonAction = LoadSound("modeles/sectionfail.wav");

    Color bgColor = GRAY;
    Vector2 mouse;
    // Texture2D newBtn = LoadTexture("modeles/btnDefault.png");
    NewButton *before = initButton("modeles/textDefault.png");
    NewButton *after = initButton("modeles/btnDefault.png");
    NewButton *currentBtn = NULL;

    Image img_circle = initTextureCircle();
    // Image appr = LoadImage("modeles/approachcircle.png");
    NewCircle *temp = initCircle(img_circle);

    Image cur = initImageCursor();
    Texture2D frame = LoadTextureFromImage(cur);

    double TimeToStart = 3.0;
    unsigned int total = 0, mistakes = 0;

    HideCursor();
    bool start_flag = false;

    while(!WindowShouldClose()){
        mouse = GetMousePosition();
        if(CheckCollisionPointRec(mouse, (Rectangle){before->crd.x, before->crd.y, before->frame.width, before->frame.height})){
            // before->cl.a = 150;
            currentBtn = after;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) start_flag = true;
        } else currentBtn = before;

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
                mistakes++;
                UnloadTexture(temp->frame);
                // UnloadTexture(temp->approach);
                free(temp);
                temp = initCircle(img_circle);
                click = false;
            }

            if(temp->lifetime.time <= 0){
                PlaySound(nonAction);
                mistakes++;
                UnloadTexture(temp->frame);
                // UnloadTexture(temp->approach);
                free(temp);
                temp = initCircle(img_circle);
            }
            
            temp->lifetime.time -= GetFrameTime();
            // if (temp->lifetime.timeLife > 0 && temp->frame.width <= temp->approach.height && temp->frame.height <= temp->approach.height){
            //     temp->approach.height -= GetFrameTime() / 2.0f;
            //     temp->approach.width -= GetFrameTime() / 2.0f;
            // }
        }
        BeginDrawing();
            ClearBackground(bgColor);
            if(!start_flag) MenuWindow(bgColor, *currentBtn, frame, mouse);
            if(start_flag) PlaygroundWindow(frame, *temp, mouse, total, mistakes, TimeToStart);
        EndDrawing();

    }
    // Вынести под функцию
    UnloadImage(icon);
    // UnloadImage(appr);
    UnloadImage(cur);
    UnloadImage(img_circle);
    UnloadTexture(before->frame);
    UnloadTexture(after->frame);
    free(after);
    free(before);
    free(currentBtn);
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