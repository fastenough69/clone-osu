#include "../headers/circle_obj.h"

int __myrand(const int cord1, const int cord2){
    int result = rand()%(cord2 - cord1 + 1) + cord1;
    return result;
}

NewCircle *initCircle(Image img){
    NewCircle *circle = malloc(sizeof(NewCircle));
    circle->frame = LoadTextureFromImage(img);
    // circle->approach = LoadTextureFromImage(appr);
    float r = circle->frame.width / 2.0f - 5;
    circle->center = (Vector2){
        __myrand((int)r, WIDHT_RES - (int)r), 
        __myrand((int)r, HEIGHT_RES - (int)r)
    };
    circle->lifetime.time = 2.0;
    circle->cl = RED;
    return circle;
}

Image initTextureCircle(){
    Image temp = LoadImage("modeles/hitcircle.png");
    ImageResize(&temp, 100, 100);
    return temp;
}

Image initImageCursor(){
    Image cursor = LoadImage("modeles/cursor.png");
    ImageResize(&cursor, 50, 50);
    return cursor;
}
