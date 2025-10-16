#include <iostream>
#include "raylib.h"
#include <vector>
#include <deque>
#include <cmath>

using std::cout, std::endl, std::vector, std::deque;

const float RADAR_PING_INTERVAL = 1.0f; // seconds
const int RADAR_AIRCRAFT_SIZE = 4; // pixels

class Airplane {
public:
    float positionX, positionY;
    int speed, altitude, heading;
    deque<float> previousX, previousY;

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
        DrawRectangle(positionX - RADAR_AIRCRAFT_SIZE, positionY - RADAR_AIRCRAFT_SIZE, RADAR_AIRCRAFT_SIZE * 2, RADAR_AIRCRAFT_SIZE * 2, WHITE);
        for (int i = 2; i < previousX.size(); i+=2) {
            DrawCircle(previousX[i], previousY[i], RADAR_AIRCRAFT_SIZE / 2, WHITE);
        }
    }
};

vector<Airplane> airplanes;
float radarPingTimer = 0;

void update(float deltaTime) {
    radarPingTimer += deltaTime;
    if (radarPingTimer < 1){
        return;
    }
    for (Airplane &airplane : airplanes) {
        airplane.update(deltaTime);
        airplane.previousX.push_front(airplane.positionX);
        airplane.previousY.push_front(airplane.positionY);
        if (airplane.previousX.size() > 10) {
            airplane.previousX.pop_back();
            airplane.previousY.pop_back();
        }
    }
    radarPingTimer = 0;
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
    airplanes.push_back(Airplane(500, 500, 160, 10000, 90));

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        update(deltaTime);
        draw();
    }
    CloseWindow();
    return 0;
}