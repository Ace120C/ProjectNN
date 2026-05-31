#ifndef SCENES_H
#define SCENES_H

typedef enum SceneID {
    TITLE,
    SKILL_SELECT,
    EXIT_SCENE
} SceneID;

SceneID TitleScene(void);
SceneID Skill_SelectScene(void);

#endif // SCENES_H


