#ifndef TOWER_DEFENSE_12_MENU_STATE_H
#define TOWER_DEFENSE_12_MENU_STATE_H
#include "window_state.h"
#include "SFML/Graphics.hpp"
#include <iostream>
// #include "../Gui.h"

class MenuState: public WindowState {
public:
    MenuState(sf::RenderWindow& window, Gui* gui);


    ~MenuState() override = default;

    void advance_state() override;

    void draw_current_state() override;



private:

};
#endif //TOWER_DEFENSE_12_MENU_STATE_H
