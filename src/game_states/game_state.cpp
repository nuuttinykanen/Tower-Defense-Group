#include "../Gui.h"
#include "game_state.h"
#include "menu_state.h"


#define TOWER_BUTTON_GRID_START_X 1050
#define TOWER_BUTTON_GRID_START_Y 75


GameState::GameState(sf::RenderWindow &window, Gui* gui) : WindowState(window, gui) {

    generateButtons();
    generateEnemies();

    auto wave = new Wave({new Zombie(), new ZombieHorde(), new Zombie(), new MichaelMyers, new Dracula, new Bat, new Zombie, new MichaelMyers});

    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> coords = std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>();
    std::pair<int, int> start = std::make_pair(2, 4);
    std::pair<int, int> middle = std::make_pair(2, 9);
    std::pair<int, int> end1 = std::make_pair(10, 9);
    std::pair<int, int> end2 = std::make_pair(10, 14);
    std::pair<int, int> end3 = std::make_pair(15, 14);
    coords.emplace_back(start, middle);
    coords.emplace_back(middle, end1);
    coords.emplace_back(end1, end2);
    coords.emplace_back(end2, end3);
    levelMap_ = new LevelMap(100);
    levelMap_->InitializePath(coords);
    player_ = new Player(100);
    game_ = new Game( *levelMap_, *player_, {wave});
    auto towerShop_ = std::vector<Tower*>();
}
GameState::~GameState() {
    for (auto b : buttons_) {
        delete b.second;
    }
    for (auto t : towerButtons_) {
        delete t.second;
    }
}

void GameState::advance_state() {
    game_->UpdateState();
}

void GameState::draw_current_state() {
    for (auto b : buttons_) {
        b.second->draw(window_);
    }
    for (auto t : towerButtons_)  {
        t.second->draw(window_);
    }
    auto globals = gui_->getGlobalObjects();

    auto purpleSprite = globals->getPurpleEnemySprite();
    purpleSprite.setScale(2, 2);
    purpleSprite.setPosition(500, 500);
    window_.draw(purpleSprite);
    LevelMap& map = game_->GetMap();
    // Draw free squares
    for(auto it : map.GetFreeSquares()) {
        auto freeSprite = globals->getFreeSquareSprite();
        freeSprite.setPosition(it.second->GetX(), it.second->GetY());
        window_.draw(freeSprite);
    }
    // Draw enemies and path
    for(auto it : map.GetEnemySquares()) {
        auto freeSprite = globals->getEnemySquareSprite();
        freeSprite.setPosition(it.second->GetX(), it.second->GetY());
        window_.draw(freeSprite);
        if(it.second->ContainsEnemies()) {
            for(Enemy* en : it.second->GetEnemies()) {
               sf::Sprite en_sprite = enemySprites_.at(en->GetName());
               en_sprite.setPosition(it.second->GetX(), it.second->GetY());
               window_.draw(en_sprite);
            }
        }
    }
    for(auto it : map.GetEnemySquares()) {
        if(it.second->ContainsEnemies()) {
            for(Enemy* en : it.second->GetEnemies()) {
                sf::Sprite en_sprite = enemySprites_.at(en->GetName());
                en_sprite.setPosition(it.second->GetX(), it.second->GetY());
                window_.draw(en_sprite);
            }
        }
    }
    // Draw towers
    for(auto it : map.GetTowerSquares()) {
        auto freeSprite = globals->getTowerSquareSprite();
        freeSprite.setPosition(it.second->GetX(), it.second->GetY());
        window_.draw(freeSprite);
    }
    // Draw projectiles
    for(auto it : map.GetProjectiles()) {
        if(it->GetLocation() != nullptr) {
            auto freeSprite = globals->getProjectileSprite();
            freeSprite.setPosition(it->GetLocation()->GetX(), it->GetLocation()->GetY());
            window_.draw(freeSprite);
        }
    }

}

void GameState::poll_events() {
    sf::Event event{};


    while (window_.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window_.close();

        // 0 -> primary click, 1-> secondary
        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == 0) {
                auto mouse_pos = window_.mapPixelToCoords(sf::Mouse::getPosition(window_));

                for (auto b : buttons_) {
                    // Move to next one if this button is not clicked
                    if (!b.second->contains(mouse_pos)) continue;
                    switch (b.first) {

                        case QuitToMenu:
                            quitToMenu();
                            return;
                        case StartWave:
                            startWave();
                            return;
                        case SellTower:
                            return;
                        case UpgradeTower:
                            return;
                    }
                }
                for (auto t : towerButtons_) {
                    if (!t.second->contains(mouse_pos)) continue;
                    switch (t.first) {

                        case Attack1: {
                            auto newTower = new Gunner();
                            if(newTower->GetPrice() <= player_->GetMoney()) {
                                buyTower(newTower);
                                std::cout << "Choosing tower!" << std::endl;
                            } else {
                                std::cout << "You don't have enough money!" << std::endl;
                                delete (newTower);
                            }
                            return;
                        }
                        case Attack2: {
                            auto newTower = new Bomber();
                            if(newTower->GetPrice() <= player_->GetMoney()) {
                                buyTower(newTower);
                                std::cout << "Choosing tower!" << std::endl;
                            } else {
                                std::cout << "You don't have enough money!" << std::endl;
                                delete (newTower);
                            }
                            return;
                        }
                        case Attack3: {
                            auto newTower = new Gunner();
                            if(newTower->GetPrice() <= player_->GetMoney()) {
                                buyTower(newTower);
                                std::cout << "Choosing tower!" << std::endl;
                            } else {
                                std::cout << "You don't have enough money!" << std::endl;
                                delete (newTower);
                            }
                            return;
                        }
                        case Attack4: {
                            auto newTower = new Gunner();
                            if(newTower->GetPrice() <= player_->GetMoney()) {
                                buyTower(newTower);
                                std::cout << "Choosing tower!" << std::endl;
                            } else {
                                std::cout << "You don't have enough money!" << std::endl;
                                delete (newTower);
                            }
                            return;
                        }
                        case Support1: {
                            auto newTower = new Gunner();
                            if(newTower->GetPrice() <= player_->GetMoney()) {
                                buyTower(newTower);
                                std::cout << "Choosing tower!" << std::endl;
                            } else {
                                std::cout << "You don't have enough money!" << std::endl;
                                delete (newTower);
                            }
                            return;
                        }
                        case Support2: {
                            auto newTower = new Gunner();
                            if(newTower->GetPrice() <= player_->GetMoney()) {
                                buyTower(newTower);
                                std::cout << "Choosing tower!" << std::endl;
                            } else {
                                std::cout << "You don't have enough money!" << std::endl;
                                delete (newTower);
                            }
                            return;
                        }
                        case Support3: {
                            auto newTower = new Gunner();
                            if(newTower->GetPrice() <= player_->GetMoney()) {
                                buyTower(newTower);
                                std::cout << "Choosing tower!" << std::endl;
                            } else {
                                std::cout << "You don't have enough money!" << std::endl;
                                delete (newTower);
                            }
                            return;
                        }
                        case Support4: {
                            auto newTower = new Gunner();
                            if(newTower->GetPrice() <= player_->GetMoney()) {
                                buyTower(newTower);
                                std::cout << "Choosing tower!" << std::endl;
                            } else {
                                std::cout << "You don't have enough money!" << std::endl;
                                delete (newTower);
                            }
                            return;
                        }
                    }
                }
            } else if (event.mouseButton.button == 1) {
                //right click does nothing
            }

        }



    }
}

void GameState::quitToMenu() {
    std::cout << "Quitting to menu!" << std::endl;
    gui_->change_game_state(new MenuState(window_, gui_));
}

void GameState::startWave() {
    game_->StartWave();
    if (game_->GetWaveCount() == 0) {
        // Remove the start wave button
        for (auto it = buttons_.begin(); it != buttons_.end(); it++) {
            if (it->first == GameButtonTarget::StartWave) {
                delete it->second;
                buttons_.erase(it);
            }
        }
    }
}

void GameState::buyTower(Tower* tower) {
    player_->AddTower(tower);
}

void GameState::generateButtons() {
    // Generate buttons
    auto startButton = new Button(sf::Vector2f (225, 50), sf::Vector2f(1050, 650),
                                  "Quit game",this->getFont(), 20);
    buttons_[GameButtonTarget::QuitToMenu] = startButton;
    auto startWaveButton = new Button(sf::Vector2f(225, 50), sf::Vector2f(1050, 590),
                                      "Start wave!", this->getFont(), 20);
    buttons_[GameButtonTarget::StartWave] = startWaveButton;
    auto upgradeTowerButton = new Button(sf::Vector2f(275, 50), sf::Vector2f(750
                                                 , 590),
                                         "Upgrade tower", this->getFont(), 20);
    buttons_[GameButtonTarget::UpgradeTower] = upgradeTowerButton;

    auto sellTowerButton = new Button(sf::Vector2f(275, 50), sf::Vector2f(750, 650),
                                      "Sell tower", this->getFont(), 20);
    buttons_[GameButtonTarget::SellTower] = sellTowerButton;

    // TODO: Add the correct sprites here when they are made
    auto attack1Button = new TowerButton(sf::Vector2f(TOWER_BUTTON_GRID_START_X, TOWER_BUTTON_GRID_START_Y), gui_->getGlobalObjects()->getTowerSquareSprite());
    towerButtons_[TowerSelectionTarget::Attack1] = attack1Button;

    auto attack2Button = new TowerButton(sf::Vector2f(TOWER_BUTTON_GRID_START_X + 100, TOWER_BUTTON_GRID_START_Y), gui_->getGlobalObjects()->getTowerSquareSprite());
    towerButtons_[TowerSelectionTarget::Attack2] = attack2Button;

    auto attack3Button = new TowerButton(sf::Vector2f(TOWER_BUTTON_GRID_START_X, TOWER_BUTTON_GRID_START_Y + 100), gui_->getGlobalObjects()->getTowerSquareSprite());
    towerButtons_[TowerSelectionTarget::Attack3] = attack3Button;

    auto attack4Button = new TowerButton(sf::Vector2f(TOWER_BUTTON_GRID_START_X + 100, TOWER_BUTTON_GRID_START_Y + 100), gui_->getGlobalObjects()->getTowerSquareSprite());
    towerButtons_[TowerSelectionTarget::Attack4] = attack4Button;

    auto support1Button = new TowerButton(sf::Vector2f(TOWER_BUTTON_GRID_START_X, TOWER_BUTTON_GRID_START_Y + 200), gui_->getGlobalObjects()->getTowerSquareSprite());
    towerButtons_[TowerSelectionTarget::Support1] = support1Button;

    auto support2Button = new TowerButton(sf::Vector2f(TOWER_BUTTON_GRID_START_X + 100, TOWER_BUTTON_GRID_START_Y + 200), gui_->getGlobalObjects()->getTowerSquareSprite());
    towerButtons_[TowerSelectionTarget::Support2] = support2Button;

    auto support3Button = new TowerButton(sf::Vector2f(TOWER_BUTTON_GRID_START_X, TOWER_BUTTON_GRID_START_Y + 300), gui_->getGlobalObjects()->getTowerSquareSprite());
    towerButtons_[TowerSelectionTarget::Support3] = support3Button;

    auto support4Button = new TowerButton(sf::Vector2f(TOWER_BUTTON_GRID_START_X + 100, TOWER_BUTTON_GRID_START_Y + 300), gui_->getGlobalObjects()->getTowerSquareSprite());
    towerButtons_[TowerSelectionTarget::Support4] = support4Button;
}

void GameState::generateEnemies() {
    enemySprites_["Zombie"] = gui_->getGlobalObjects()->getZombieSprite();
    enemySprites_["Michael Myers"] = gui_->getGlobalObjects()->getMichaelSprite();
    enemySprites_["Zombie Horde"] = gui_->getGlobalObjects()->getHordeSprite();
    enemySprites_["Dracula"] = gui_->getGlobalObjects()->getDraculaSprite();
    enemySprites_["Bat"] = gui_->getGlobalObjects()->getBatSprite();
}

