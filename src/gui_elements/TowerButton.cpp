#include "TowerButton.h"

TowerButton::TowerButton(Vector2f pos, sf::Sprite& towerSprite) :
        box_(RectangleShape(Vector2f(90, 90))),
        icon_(towerSprite),
        pos_(pos)
{
    box_.setPosition(pos);
    box_.setOutlineColor(Color::Black);
    box_.setOutlineThickness(5);
    box_.setFillColor(Color::White);
}

void TowerButton::draw(sf::RenderWindow &window) {
    window.draw(box_);

    icon_.setPosition(pos_.x + 15, pos_.y + 15);
    icon_.setScale(3, 3);
    window.draw(icon_);


}

bool TowerButton::contains(Vector2f pos) {
    if (box_.getGlobalBounds().contains(pos)) {
        return true;
    } else {
        return false;
    }
}
