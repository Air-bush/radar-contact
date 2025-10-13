#include <iostream>
#include "raylib.h"

using std::cout, std::endl;

void draw() {
    BeginDrawing();
    ClearBackground(Color{20, 20, 25, 255});
    EndDrawing();
}

int main() {
    InitWindow(1920, 1080, "Radar Contact");
    ToggleFullscreen();

    SetExitKey(KEY_NULL);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        draw();
    }
    CloseWindow();
    return 0;
}