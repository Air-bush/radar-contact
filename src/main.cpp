#include <iostream>
#include <raylib.h>

using std::cout, std::endl;

int main() {
    InitWindow(800, 600, "Radar Contact");
    cout << "Ready: " << IsWindowReady() << endl;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(Color{20, 20, 25, 255});
        EndDrawing();
    }
    CloseWindow();
    return 0;
}