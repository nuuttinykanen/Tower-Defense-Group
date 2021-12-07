#ifndef TOWER_DEFENSE_12_GLOBALOBJECTS_H
#define TOWER_DEFENSE_12_GLOBALOBJECTS_H
#include "SFML/Graphics.hpp"
#include <iostream>
// Contains fonts, sprites, etc. so they don`t have to be initalized everytime
class GlobalObjects {
public:
    GlobalObjects();
    sf::Font& getFont() { return font_; };

    sf::Sprite& getEnemySprite(float scaledBy = 1);
    sf::Sprite& getPurpleEnemySprite(float scaledBy = 1);

    sf::Sprite& getFreeSquareSprite(float scaledBy = 1);
    sf::Sprite& getEnemySquareSprite(float scaledBy = 1);
    sf::Sprite& getTowerSquareSprite(float scaledBy = 1);
    sf::Sprite& getRangeSprite(float scaledBy = 1);

    sf::Sprite& getHordeSprite(float scaledBy = 1);
    sf::Sprite& getZombieSprite(float scaledBy = 1);
    sf::Sprite& getDraculaSprite(float scaledBy = 1);
    sf::Sprite& getBatSprite(float scaledBy = 1);
    sf::Sprite& getMichaelSprite(float scaledBy = 1);
    sf::Sprite& getProjectileSprite(float scaleBy = 1);
    sf::Sprite& getBomberSprite(float scaleBy = 1);
    sf::Sprite& getGunnerSprite(float scaleBy = 1);
    sf::Sprite& getBombProjecSprite(float scaleBy = 1);
    sf::Sprite& getGunProjecSprite(float scaleBy = 1);

    sf::Sprite& getSuperBomberSprite(float scaledBy = 1);
    sf::Sprite& getUltraBomberSprite(float scaledBy = 1);
    sf::Sprite& getClockerSprite(float scaledBy = 1);
    sf::Sprite& getClockBlockerSprite(float scaledBy = 1);
    sf::Sprite& getSeerSprite(float scaledBy = 1);
    sf::Sprite& getMotherBrainSprite(float scaledBy = 1);
    sf::Sprite& getMultigunnerSprite(float scaledBy = 1);
    sf::Sprite& getGunFiendSprite(float scaledBy = 1);
    sf::Sprite& getStereoDudeSprite(float scaledBy = 1);
    sf::Sprite& getDJDudeSprite(float scaledBy = 1);

private:
    sf::Font font_;
    sf::Texture enemyTexture_;
    sf::Texture purpleEnemyTexture_;
    sf::Texture freeSquareTexture_;
    sf::Texture enemySquareTexture_;
    sf::Texture towerSquareTexture_;
    sf::Texture rangeTexture_;

    sf::Texture superBomberTexture_;
    sf::Texture ultraBomberTexture_;
    sf::Texture clockerTexture_;
    sf::Texture clockBlockerTexture_;
    sf::Texture seerTexture_;
    sf::Texture motherBrainTexture_;
    sf::Texture multigunnerTexture_;
    sf::Texture gunFiendTexture_;
    sf::Texture stereoDudeTexture_;
    sf::Texture djDudeTexture_;

    sf::Texture hordeTexture_;
    sf::Texture zombieTexture_;
    sf::Texture draculaTexture_;
    sf::Texture batTexture_;
    sf::Texture michaelTexture_;
    sf::Texture bomberTexture_;
    sf::Texture gunnerTexture_;
    sf::Texture bombProjecTexture_;
    sf::Texture gunProjecTexture_;

    sf::Sprite enemySprite_;
    sf::Sprite purpleEnemySprite_;
    sf::Sprite freeSquareSprite_;
    sf::Sprite enemySquareSprite_;
    sf::Sprite towerSquareSprite_;
    sf::Sprite rangeSprite_;

    sf::Sprite superBomberSprite_;
    sf::Sprite ultraBomberSprite_;
    sf::Sprite clockerSprite_;
    sf::Sprite clockBlockerSprite_;
    sf::Sprite seerSprite_;
    sf::Sprite motherBrainSprite_;
    sf::Sprite multigunnerSprite_;
    sf::Sprite gunFiendSprite_;
    sf::Sprite stereoDudeSprite_;
    sf::Sprite djDudeSprite_;

    sf::Sprite hordeSprite_;
    sf::Sprite zombieSprite_;
    sf::Sprite draculaSprite_;
    sf::Sprite batSprite_;
    sf::Sprite michaelSprite_;
    sf::Sprite bomberSprite_;
    sf::Sprite gunnerSprite_;
    sf::Sprite bombProjecSprite_;
    sf::Sprite gunProjecSprite_;
};


#endif //TOWER_DEFENSE_12_GLOBALOBJECTS_H
