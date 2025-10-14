#include <iostream>
#include "raylib.h"
#include <list>
#include <cmath>

using std::cout, std::endl, std::list;
class Airplane {
public:
    float positionX, positionY;
    int speed, altitude, heading;
    float previousX[5], previousY[5];

    Airplane(int startX, int startY, int startSpeed, int startAltitude, int startHeading) {
        positionX = startX;
        positionY = startY;
        speed = startSpeed;
        altitude = startAltitude;
        heading = startHeading;
    }

    void update(float deltaTime) {
        float velocity = speed * 0.02;
        float angle = heading * (M_PI / 180);
        positionX += velocity * sin(angle);
        positionY -= velocity * cos(angle);
    }

    void draw() {
        DrawCircle(positionX, positionY, 5, WHITE);
    }
};

list<Airplane> airplanes;
float radarPingTimer = 0;

void update(float deltaTime) {
    radarPingTimer += deltaTime;
    if (radarPingTimer >= 1) {
        for (Airplane &airplane : airplanes) {
            airplane.update(deltaTime);
            airplane.previousX.push_front(airplane.positionX);
            airplane.previousX.pop_back();
            airplane.previousY.push_front(airplane.positionY);
            airplane.previousY.pop_back();
        }
        radarPingTimer = 0;
    }
}

void draw() {
    BeginDrawing();
    ClearBackground(Color{20, 20, 25, 255});
    for (Airplane &airplane : airplanes) {
        airplane.draw();
    }
    EndDrawing();
}

int main() {
    InitWindow(1920, 1080, "Radar Contact");
    ToggleFullscreen();
    SetTargetFPS(120);

    SetExitKey(KEY_NULL);
    airplanes.push_back(Airplane(500, 500, 250, 10000, 90));

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        update(deltaTime);
        draw();
    }
    CloseWindow();
    return 0;
}