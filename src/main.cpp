#include <iostream>
#include "raylib.h"

using std::cout, std::endl;

int main() {
    InitWindow(1920, 1080, "Radar Contact");
    ToggleFullscreen();

    SetExitKey(KEY_NULL);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(Color{20, 20, 25, 255});
        EndDrawing();
    }
    CloseWindow();
    return 0;
}