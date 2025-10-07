#include <raylib.h>
#include <stdbool.h>
#include "scenes.h"

SceneID TitleScene(void)
{
  Music Menu_bgm = LoadMusicStream("./music/menu.mp3");
  PlayMusicStream(Menu_bgm);
  Texture2D Cloud = LoadTexture("./assets/cloud.png");
  Vector2 Cloud1_Pos = {30, 10};
  Vector2 Cloud2_Pos = {350, 150};
  Vector2 Cloud3_Pos = {650, 10};
  Vector2 Cloud4_Pos = {850, 150};
  Rectangle StartButton_Pos = {480, 450, 288, 288};
  Vector2 Velocity = {50, 0};
  bool start_pressed =  false;
  bool start_hovered =  false;
  Texture2D Logo = LoadTexture("./assets/logo.png");
  Texture2D start_button = LoadTexture("./assets/start-button.png");
  Texture2D start_button_hover = LoadTexture("./assets/start-button-hover.png");
 
  SetTargetFPS(60);


  while(WindowShouldClose() == false) 
  { 
    UpdateMusicStream(Menu_bgm);

    Cloud1_Pos.x += Velocity.x * GetFrameTime();
    Cloud1_Pos.y += Velocity.y * GetFrameTime();

    Cloud2_Pos.x += Velocity.x * GetFrameTime();
    Cloud2_Pos.y += Velocity.y * GetFrameTime();

    Cloud3_Pos.x += Velocity.x * GetFrameTime();
    Cloud3_Pos.y += Velocity.y * GetFrameTime();

    Cloud4_Pos.x += Velocity.x * GetFrameTime();
    Cloud4_Pos.y += Velocity.y * GetFrameTime();

    if (Cloud1_Pos.x >= 1285.0) {
      Cloud1_Pos.x = -300.0f;
    }
    if (Cloud2_Pos.x >= 1285.0) {
      Cloud2_Pos.x = -300.0f;
    }
    if (Cloud3_Pos.x >= 1285.0) {
      Cloud3_Pos.x = -300.0f;
    }
    if (Cloud4_Pos.x >= 1285.0) {
      Cloud4_Pos.x = -300.0f;
    }

    Vector2 mouse = GetMousePosition();

    if (!start_pressed && 
      IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
      CheckCollisionPointRec(mouse, StartButton_Pos)) {
      start_pressed = true;
      return CHAR_SELECT;
    }

    if (!start_pressed &&
    CheckCollisionPointRec(mouse, StartButton_Pos)) {
      start_hovered = true;
    } else {
      start_hovered = false;
    }

    BeginDrawing();
    ClearBackground(GetColor(0x249FDEFF));
    DrawRectangle(0, 500, 1280, 300, SKYBLUE);
    DrawRectangle(0, 420, 1280, 200, GetColor(0x56B7F7FF));
    DrawRectangle(0, 300, 1280, 200, GetColor(0x45AFEEFF));
    DrawTextureV(Cloud, Cloud1_Pos, RAYWHITE);
    DrawTextureV(Cloud, Cloud2_Pos, RAYWHITE);
    DrawTextureV(Cloud, Cloud3_Pos, RAYWHITE);
    DrawTextureV(Cloud, Cloud4_Pos, RAYWHITE);
    Vector2 Button_Pos = {StartButton_Pos.x, StartButton_Pos.y};
    if (!start_hovered && !start_pressed) {
      DrawTextureV(start_button, Button_Pos, RAYWHITE);
    } else if (start_hovered) {
      DrawTextureV(start_button_hover, Button_Pos , RAYWHITE);
    } else if (!start_pressed) {
      DrawTextureV(start_button_hover, Button_Pos, RAYWHITE);
    }  
    DrawTexture(Logo, 220, 200, RAYWHITE);
    EndDrawing();
  }

  UnloadTexture(Cloud);
  UnloadTexture(Logo);
  UnloadTexture(start_button);
  UnloadTexture(start_button_hover);
  StopMusicStream(Menu_bgm);
  return TITLE;
}

