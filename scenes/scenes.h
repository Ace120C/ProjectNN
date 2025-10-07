#ifndef SCENES_H
#define SCENES_H

typedef enum SceneID {
    TITLE,
    CHAR_SELECT,
    EXIT_SCENE
} SceneID;

SceneID TitleScene(void);
SceneID CharSelectScene(void);

#endif // SCENES_H


