#include "raylib.h"

#define MAX_TOUCH_POINTS 10

int main(void) {
    InitWindow(0, 0, "raylib [core] example - input multitouch");

    Vector2 touchPositions[MAX_TOUCH_POINTS] = {0};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        for (int i = 0; i < MAX_TOUCH_POINTS; ++i)
            touchPositions[i] = GetTouchPosition(i);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        for (int i = 0; i < MAX_TOUCH_POINTS; ++i) {

            if ((touchPositions[i].x > 0) && (touchPositions[i].y > 0)) {

                DrawCircleV(touchPositions[i], 34, ORANGE);
                DrawText(
                    TextFormat("%d", i), (int)touchPositions[i].x - 10,
                    (int)touchPositions[i].y - 70, 40, BLACK
                );
            }
        }

        DrawText(
            "touch the screen at multiple locations to get multiple balls", 10,
            10, 20, DARKGRAY
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}