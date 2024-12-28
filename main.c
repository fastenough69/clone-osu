/*
    Нужено разобрраться с отностилеьными путям к файлам текстур. +
    Нужно сделать меню с текстурами и анимациями:
        -сделать кнопку старта ++
        -сделать возможность менять сложность:++
            --изменять время жизни круга ++
            --изменять размер круга++
        -сделать возможность создавать сколько времени будет идти раунд
        -*сделать возможность изменения чувствательности мыши
    Нужно сделать новый подсчет очков опираясь на сложность +-
    Нужно сделать рестарт++
    Нужно сделать разрешение динимичекое+
    Нужно сделать возможность взаимодействия не только с кнопками мыши
*/

// #include "headers/InterfaceWindow.h"
#include "headers/myutils.h"

int main(void){
    InitWindow(WIDHT_RES, HEIGHT_RES, "Killer OSU!");
    SetTargetFPS(200);
    Image icon = LoadImage("modeles/target_icon_264154.png");
    SetWindowIcon(icon);
    InitAudioDevice();
    

    ToggleFullscreen();

    Sound actionClick = LoadSound("modeles/soft-hitnormal.wav");
    Sound nonAction = LoadSound("modeles/sectionfail.wav");

    Color bgColor = GRAY;
    Vector2 mouse;
    NewButton *before = initButton("modeles/textDefault.png");
    NewButton *after = initButton("modeles/btnDefault.png");
    NewButton *currentBtn = NULL;
    NewButton *repeat = initButton("modeles/Default.png");
        repeat->crd.x = WIDHT_RES - 100;
        repeat->crd.y = HEIGHT_RES - 100;

    Image img_circle = initTextureCircle(BASE_SIZE_CIRCLE);
    // Image appr = LoadImage("modeles/approachcircle.png");
    NewCircle *temp = initCircle(img_circle, 3.0);

    Slider *sldTime = initSlider("Change lifetime", 150);
    Slider *sldSize = initSlider("Change size circle", 250);
    Slider *sldSens = initSlider("Change sens", 350);
    // Slider *sldTimeRound = initSlider("Time round", 450);

    Image cur = initImageCursor();
    Texture2D frame = LoadTextureFromImage(cur);

    double TimeToStart = 3.0;
    unsigned int combo = 0, total = 0;

    HideCursor();
    bool start_flag = false;

    while(!WindowShouldClose()){
        mouse = GetMousePosition();
        if(CheckCollisionPointRec(mouse, (Rectangle){before->crd.x, before->crd.y, before->frame.width, before->frame.height})){
            currentBtn = after;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) start_flag = true;
        } else currentBtn = before;

        if(CheckCollisionPointCircle(mouse, sldTime->pos_circle, sldTime->rad_circle) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            sldTime->rec.width = mouse.x - sldTime->rec.x;
            sldTime->pos_circle.x = mouse.x;
            sldTime->value_pos.x = sldTime->pos_circle.x;
            sldTime->value = sldTime->rec.width / 100.0f;
            if(sldTime->rec.width < 50){
                sldTime->rec.width = 50;
                sldTime->pos_circle.x = sldTime->rec.x + 50;
            }
            if(sldTime->rec.width > sldTime->full_widht){
                sldTime->rec.width = sldTime->full_widht;
                sldTime->pos_circle.x = sldTime->rec.x + sldTime->full_widht;
            }
            temp->lifetime.time = sldTime->value;
        }

        if(CheckCollisionPointCircle(mouse, sldSize->pos_circle, sldSize->rad_circle) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            sldSize->rec.width = mouse.x - sldSize->rec.x;
            sldSize->pos_circle.x = mouse.x;
            sldSize->value_pos.x = sldSize->pos_circle.x;
            sldSize->value = sldSize->rec.width;
            if(sldSize->rec.width < 50){
                sldSize->rec.width = 50;
                sldSize->pos_circle.x = sldSize->rec.x + 50;
            }
            if(sldSize->rec.width > sldSize->full_widht){
                sldSize->rec.width = sldSize->full_widht;
                sldSize->pos_circle.x = sldSize->rec.x + sldSize->full_widht;
            }
            temp->frame.width = sldSize->value;
            temp->frame.height = sldSize->value;
        }

        if(CheckCollisionPointCircle(mouse, sldSens->pos_circle, sldSens->rad_circle) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            sldSens->rec.width = mouse.x - sldSens->rec.x;
            sldSens->pos_circle.x = mouse.x;
            sldSens->value_pos.x = sldSens->pos_circle.x;
            sldSens->value = sldSens->rec.width;
            if(sldSens->rec.width < 50){
                sldSens->rec.width = 50;
                sldSens->pos_circle.x = sldSens->rec.x + 50;
            }
            if(sldSens->rec.width > sldSens->full_widht){
                sldSens->rec.width = sldSens->full_widht;
                sldSens->pos_circle.x = sldSens->rec.x + sldSens->full_widht;
            }
            // ChangeMouseSpeed(1, 1);
        }
        // ColSliders(mouse, sldTime, sldTime->rec.width / 100.0f);

        if(start_flag) TimeToStart -= GetFrameTime();


        if(start_flag && TimeToStart <= 0){
            bool click = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
            if(CheckCollisionPointCircle(mouse, temp->center, temp->frame.width / 2.0f - 5) && click){
                PlaySound(actionClick);
                combo++;
                total += ((500.0f / (sldTime->value - temp->lifetime.time)) * combo) / (sldSize->value / 100.0f + sldTime->value / 10.0f);
                UnloadTexture(temp->frame);
                // UnloadTexture(temp->approach);
                free(temp);
                temp = initCircle(img_circle, sldTime->value);
                temp->frame.width = temp->frame.height = sldSize->value;
                click = false;
            }

            if(!CheckCollisionPointCircle(mouse, temp->center, temp->frame.width / 2.0f - 5) && click){
                PlaySound(nonAction);
                combo = 0;
            }

            if(temp->lifetime.time <= 0){
                PlaySound(nonAction);
                combo = 0;
                UnloadTexture(temp->frame);
                // UnloadTexture(temp->approach);
                free(temp);
                temp = initCircle(img_circle, sldTime->value);
                temp->frame.width = temp->frame.height = sldSize->value; //???
                click = false;
            }
            
            temp->lifetime.time -= GetFrameTime();
            if(CheckCollisionPointRec(mouse, (Rectangle){repeat->crd.x, repeat->crd.y, repeat->frame.width, repeat->frame.height}) && click){
                TimeToStart = 3.0;
                combo = 0;
                total = 0;
            }
            // if(combo == 100) WaitTime(100);
            // if (temp->lifetime.timeLife > 0 && temp->frame.width <= temp->approach.height && temp->frame.height <= temp->approach.height){
            //     temp->approach.height -= GetFrameTime() / 2.0f;
            //     temp->approach.width -= GetFrameTime() / 2.0f;
            // }
        }
        sldTime->value = sldTime->rec.width / 100.0f;
        sldSize->value = sldSize->rec.width;
        BeginDrawing();
            ClearBackground(bgColor);
            if(!start_flag) MenuWindow(bgColor, *currentBtn, frame, mouse, *sldTime, *sldSize, *sldSens);
            if(start_flag) PlaygroundWindow(frame, *temp, mouse, combo, total, TimeToStart, *repeat);
            DrawRectangleLines(400 + temp->frame.width - 5,temp->frame.width - 5, 1120, HEIGHT_RES, GREEN);
        EndDrawing();

    }
    // Вынести под функцию
    UnloadImage(icon);
    // UnloadImage(appr);
    UnloadImage(cur);
    UnloadImage(img_circle);
    UnloadTexture(before->frame);
    UnloadTexture(after->frame);
    UnloadTexture(repeat->frame);
    free(repeat);
    free(after);
    free(before);
    UnloadSound(actionClick);
    UnloadSound(nonAction);
    UnloadTexture(frame);
    // UnloadTexture(temp->approach);
    UnloadTexture(temp->frame);
    free(temp);
    free(sldTime);
    // ChangeMouseSpeed(0, 0);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}