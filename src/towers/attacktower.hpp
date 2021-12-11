#pragma once
#include "tower.hpp"
#include <string>
#include "../enemy.hpp"
#include "../projectile.hpp"
class AttackTower : public Tower {
    public:
    AttackTower(std::string name, std::string description, unsigned int strength, unsigned int range, int cooldown, unsigned int cost) :
    Tower(name, description, strength, range, cost),
    cooldownLimit_(cooldown), cooldown_(0), cooldownModifiers_(0), attackCounter_(0), rangeModifiers_(0) {}

    ~AttackTower() override = default;;

    int CurrentCooldown() const;

    int GetCooldownLimit() const;
    
    double CooldownPercentage() const;

    bool CanAttack() const;

    void RestartCooldown();

    void Reload();

    void AddCooldownModifier(int amount);

    void AddRangeModifier(int amount);

    void ResetModifiers();

    unsigned int GetCurrentRange() const;

    virtual Projectile* GetProjectile() = 0;

    virtual unsigned int GetRange() const;

    private:
    int cooldownLimit_;
    int cooldown_;
    int cooldownModifiers_;
    unsigned int attackCounter_;
    unsigned int rangeModifiers_;



    virtual std::string GetMainType() const;
};

class Bomber : public AttackTower {
    public:
    Bomber() : AttackTower("Bomber", "Launches bombs that also deal\ndamage to enemies next to a target", 6, 2, 35, 500) { }
    ~Bomber(){}
    virtual Projectile* GetProjectile();

    virtual TowerTypes getType() const {return TowerTypes::BomberType;}

    virtual Tower* Upgrade();
};

class SuperBomber : public AttackTower {
    public:
    SuperBomber() : AttackTower("Super Bomber", "Launches bombs that also deal\ndamage to enemies next to a target", 7, 3, 30, 510) { }
    virtual Projectile* GetProjectile();

    virtual TowerTypes getType() const {return TowerTypes::SuperBomberType;}

    virtual Tower* Upgrade();
};

class UltraBomber : public AttackTower {
    public:
    UltraBomber() : AttackTower("Ultra Bomber", "Launches bombs that also deal\ndamage to enemies next to a target", 10, 4, 25, 700) { }
    virtual Projectile* GetProjectile();

    bool CanUpgrade() override {return false;}

    virtual TowerTypes getType() const {return TowerTypes::UltraBomberType;}

    virtual Tower* Upgrade();
};

class Gunner : public AttackTower {
    public:
    Gunner() : AttackTower("Gunner", "Guns enemies.", 2, 5, 30, 300) { }
    ~Gunner(){}
    virtual Projectile* GetProjectile();

    virtual TowerTypes getType() const {return TowerTypes::GunnerType;}

    virtual Tower* Upgrade();
};

class Multigunner : public AttackTower {
    public:
    Multigunner() : AttackTower("Multigunner", "Same gunner. More guns.", 4, 5, 20, 500) { }
    ~Multigunner(){}
    virtual Projectile* GetProjectile();

    virtual TowerTypes getType() const {return TowerTypes::MultiGunnerType;}

    virtual Tower* Upgrade();
};

class GunFiend : public AttackTower {
    public:
    GunFiend() : AttackTower("Gun Fiend", "The gunner became a gun themselves.", 6, 6, 18, 550) { }
    ~GunFiend(){}
    virtual Projectile* GetProjectile();

    bool CanUpgrade() override {return false;}

    virtual TowerTypes getType() const {return TowerTypes::GunFiendType;}

    virtual Tower* Upgrade();
};

class CursedKid : public AttackTower {
public:
    CursedKid() : AttackTower("Cursed Kid", "Damages and sends enemies back by two squares.", 2, 5, 60, 300) { }
    ~CursedKid(){}
    virtual Projectile* GetProjectile();

    virtual TowerTypes getType() const {return TowerTypes::CursedKidType;}

    virtual Tower* Upgrade();
};

class MaskedKid : public AttackTower {
public:
    MaskedKid() : AttackTower("Masked Kid", "Damages and sends enemies back\nby three squares.", 2, 5, 50, 300) { }
    ~MaskedKid(){}
    virtual Projectile* GetProjectile();

    virtual TowerTypes getType() const {return TowerTypes::MaskedKidType;}

    virtual Tower* Upgrade();
};

class MaskedGod : public AttackTower {
public:
    MaskedGod() : AttackTower("Masked God", "Damages and sends enemies back\nby five squares.", 2, 5, 70, 300) { }
    ~MaskedGod(){}
    virtual Projectile* GetProjectile();

    virtual TowerTypes getType() const {return TowerTypes::MaskedGodType;}

    virtual Tower* Upgrade();
};

class KnifeBot : public AttackTower {
public:
    KnifeBot() : AttackTower("Knife Bot", "Attacks close and hard.", 8, 1, 20, 300) { }
    ~KnifeBot(){}
    virtual Projectile* GetProjectile();

    virtual TowerTypes getType() const {return TowerTypes::KnifeBotType;}

    virtual Tower* Upgrade();
};

class KnifeBot2 : public AttackTower {
public:
    KnifeBot2() : AttackTower("Knife Bot 2.0", "Attacks close and hard.", 16, 1, 30, 300) { }
    ~KnifeBot2(){}
    virtual Projectile* GetProjectile();

    virtual TowerTypes getType() const {return TowerTypes::KnifeBot2Type;}

    virtual Tower* Upgrade();
};

class SwordBot : public AttackTower {
public:
    SwordBot() : AttackTower("Sword Bot", "Attacks close and hard.", 20, 2, 30, 300) { }
    ~SwordBot(){}
    virtual Projectile* GetProjectile();

    virtual TowerTypes getType() const {return TowerTypes::SwordBotType;}

    virtual Tower* Upgrade();
};