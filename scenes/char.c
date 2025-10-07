#include <raylib.h>
#include "scenes.h"

SceneID CharSelectScene(void)
{
  Music CharSelect = LoadMusicStream("./music/char.mp3");
  Texture2D NNProfile = LoadTexture("./assets/NN.png");
  Texture2D GSProfile = LoadTexture("./assets/gold ship.png");
  InitAudioDevice();
  PlayMusicStream(CharSelect);

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    UpdateMusicStream(CharSelect);
    BeginDrawing();
    ClearBackground(GRAY);
    DrawTexture(NNProfile, 150, 50, RAYWHITE);
    DrawTexture(GSProfile, 700, 50, RAYWHITE);
    DrawText("Choose Your Character", 340, 670, 50, RED);
    EndDrawing();

    if (IsKeyPressed(KEY_T)) {
      return TITLE;
    }
  }
  UnloadTexture(NNProfile);
  UnloadTexture(GSProfile);
  StopMusicStream(CharSelect);
  return CHAR_SELECT;
}
