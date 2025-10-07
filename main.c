#include <raylib.h>
#include "scenes/scenes.h"

int main(void)
{
    InitWindow(1280, 720, "umamusume: NN");
    InitAudioDevice();
    SetTargetFPS(60);

    SceneID current = TITLE;

    while (!WindowShouldClose() && current != EXIT_SCENE) {
        switch (current) {
            case TITLE:       current = TitleScene();       break;
            case CHAR_SELECT: current = CharSelectScene();  break;
            default:          current = EXIT_SCENE;         break;
        }
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
