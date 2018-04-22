#ifndef TOWERDEFENSE_BULLETLVLONE_H
#define TOWERDEFENSE_BULLETLVLONE_H


#include "Bullet.h"

class BulletLvlOne: public Bullet {
public:
    BulletLvlOne(const sf::Vector2f& position, float angle, Warrior& target);

    static const int kDamage_ = 10;
    constexpr static const float kVelocity_ = 100;

    const Type type_ = Type ::lvlOne;
};


#endif //TOWERDEFENSE_BULLETLVLONE_H
