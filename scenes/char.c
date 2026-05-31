#include <raylib.h>
#include "scenes.h"

SceneID Skill_SelectScene(void)
{
  Music SkillMenu = LoadMusicStream("./music/char.mp3");
  Texture2D Background = LoadTexture("./assets/bg.png");
  Texture2D Square = LoadTexture("./assets/square.png");
  SceneID Next_Scene = SKILL_SELECT;
  PlayMusicStream(SkillMenu);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    UpdateMusicStream(SkillMenu);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(Background, 0, 0, RAYWHITE);
    DrawTexture(Square, 10, 52, RAYWHITE);
    EndDrawing();

    if (IsKeyPressed(KEY_T)) {
      Next_Scene = TITLE;
      break;
    }
  }
  UnloadTexture(Background);
  StopMusicStream(SkillMenu);
  return Next_Scene;
}
