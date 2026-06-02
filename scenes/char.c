#include <raylib.h>
#include "scenes.h"

SceneID Skill_SelectScene(void)
{
  Music SkillMenu = LoadMusicStream("./music/char.mp3");
  Texture2D Background = LoadTexture("./assets/bg.png");
  Texture2D Square = LoadTexture("./assets/square.png");
  Texture2D Square2 = LoadTexture("./assets/square2.png");
  Texture2D Square3 = LoadTexture("./assets/square3.png");
  SceneID Next_Scene = SKILL_SELECT;
  PlayMusicStream(SkillMenu);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    UpdateMusicStream(SkillMenu);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(Background, 0, 0, RAYWHITE);
    DrawTexture(Square, 10, 45, RAYWHITE);
    DrawTexture(Square2, 30, 370, RAYWHITE);
    DrawTexture(Square3, 360, 20, RAYWHITE);
    EndDrawing();

    if (IsKeyPressed(KEY_T)) {
      Next_Scene = TITLE;
      break;
    }
  }
  UnloadTexture(Background);
  UnloadTexture(Square);
  UnloadTexture(Square2);
  UnloadTexture(Square3);
  StopMusicStream(SkillMenu);
  return Next_Scene;
}
