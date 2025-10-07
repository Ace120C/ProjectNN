#include <raylib.h>
#include "scenes.h"

SceneID CharSelectScene(void)
{
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("char select scene", 300, 300, 50, RAYWHITE);
    EndDrawing();

    if (IsKeyPressed(KEY_T)) {
      return TITLE;
    }
  }
  return CHAR_SELECT;
}
