#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Raylib + VS Code on Ubuntu");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, Raylib!", 300, 280, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

