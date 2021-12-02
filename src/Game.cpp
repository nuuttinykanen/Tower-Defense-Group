#include "Game.hpp"

Game::~Game(){
    for(auto w : enemyWaves_) {
        delete(w);
    }
    enemyWaves_.clear();

}

void Game::SpawnEnemy(Enemy* enemy) {
    //Enemypath start square (spawn) coordinates
    int x = this->map_.GetEnemySquares().begin()->first.first;
    int y = this-> map_.GetEnemySquares().begin()->first.second;


    if(this->map_.PlaceEnemy( x, y ,enemy)){
        enemies_.push_back(enemy);
    }

}

void Game::SpawnTower(Tower* tower, double x, double y) {
    this->player_.BuyTower(tower);
    this->map_.PlaceTower(x, y, tower);
    towers_.push_back(tower);

}


void Game::KillEnemy(Enemy *enemy) {
    this->map_.EraseEnemy(enemy);
    this->player_.GiveMoney(enemy->GetBounty());
    // Remove projectile
}


void Game::SellTower(Tower* tower) {
    this->player_.SellTower(tower);
    this->map_.EraseTower(tower);
}



// Start the first wave and then remove it from the vector
void Game::StartWave() {

    this->WaveInProgress_ = true;
    auto wave = enemyWaves_[0];
    auto enemyWave = wave->getWaveEnemies();
    enemyWaves_.erase(enemyWaves_.begin());
    for(auto e : enemyWave){
        SpawnEnemy(e);
    }

}

void Game::EndGame() {
    this->GameEnd_ = true;
}

LevelMap &Game::GetMap() {
    return map_;
}

void Game::UpdateState() {


    if(!this->GameEnd_){

        if(this->WaveInProgress_){
            //Print enemy locations
            for(auto it: this->enemies_){
                this->map_.FindEnemy(it)->PrintLocation();
            }
            //Move enemies, end game if any passes
            this->map_.MoveEnemies();
            if(this->map_.GetEnemiesPassed() > 0){
                this->EndGame();
            }

            //Move Projectiles
            this->map_.MoveProjectiles();

            /*Attacktowers shoot or reload
            for(auto it : this->map_.GetAttackTowers()){
                if(it->CanAttack()){
                    this->map_.ShootProjectile(it);
                } else{
                    it->Reload();
                }
            }*/

        }



    }






}





