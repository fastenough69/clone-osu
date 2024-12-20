/*
    Нужено разобрраться с отностилеьными путям к файлам текстур. +
    Нужно сделать меню с текстурами и анимациями:
        -сделать кнопку старта +
        -сделать возможность менять сложность:
            --изменять время жизни круга
            --изменять размер круга
        -сделать возможность создавать сколько времени будет идти раунд
        -*сделать возможность изменения чувствательности мыши мыши
    Нужно сделать новый подсчет очков опираясь на сложность
    Нужно сделать возможность взаимодействия не только с кнопками мыши
    

*/

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
    // Texture2D newBtn = LoadTexture("modeles/btnDefault.png");
    NewButton *new = initButton("modeles/btnDefault.png");

    Image img_circle = initTextureCircle();
    // Image appr = LoadImage("modeles/approachcircle.png");
    NewCircle *temp = initCircle(img_circle);

    Image cur = initImageCursor();
    Texture2D frame = LoadTextureFromImage(cur);

    double TimeToStart = 3.0;
    unsigned int total = 0, misstakes = 0;

    HideCursor();
    bool start_flag = false;

    while(!WindowShouldClose()){
        mouse = GetMousePosition();
        if(CheckCollisionPointRec(mouse, (Rectangle){new->crd.x, new->crd.y, new->frame.width, new->frame.height})){
            new->cl.a = 150;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) start_flag = true;
        } else new->cl.a = 255;

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

            if(temp->lifetime.time <= 0){
                PlaySound(nonAction);
                misstakes++;
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
            if(!start_flag) MenuWindow(bgColor, *new, frame, mouse);
            if(start_flag) PlaygroundWindow(frame, *temp, mouse, total, misstakes, TimeToStart);
        EndDrawing();

    }
    // Вынести под функцию
    UnloadImage(icon);
    // UnloadImage(appr);
    UnloadImage(cur);
    UnloadImage(img_circle);
    UnloadTexture(new->frame);
    free(new);
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