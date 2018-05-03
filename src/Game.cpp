#include "Game.h"
#include "MenuState.h"
#include "PauseState.h"
#include "GameState.h"

Game::Game() : window({1000, 1000}, "Tower Defense", sf::Style::Titlebar |
        sf::Style::Default, sf::ContextSettings{0, 0, 8, 1, 1, 0, false}),
               context(window, font, textureHolder, fontHolder, cursor),
               stateManager(context) {
    loadAllResources();
    registerStates();
    stateManager.pushState(States::ID::Game);
}

void Game::run() {
    const sf::Time frameTime = sf::seconds(1.f / 60.f);
    sf::Clock clock;
    sf::Time passedTime = sf::Time::Zero;

    while (window.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        passedTime += elapsedTime;
        while (passedTime > frameTime) {
            passedTime -= frameTime;
            input();
            update(frameTime);
        }
        draw();
    }
}

void Game::input() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        stateManager.processEvents(event);
    }
}

void Game::loadAllResources() {
    fontHolder.load(Fonts::font1, "Resources/sansation.ttf");

    textureHolder.load(Textures::cursor, "Resources/cursor.png");
    textureHolder.load(Textures::panel, "Resources/panel.png");
    textureHolder.load(Textures::button, "Resources/button.png");
    textureHolder.load(Textures::map, "Resources/map.png");
    textureHolder.load(Textures::target, "Resources/target.png");
    textureHolder.load(Textures::gold, "Resources/diamond.png");
    textureHolder.load(Textures::star, "Resources/star.png");
    textureHolder.load(Textures::exit, "Resources/exit.png");
    textureHolder.load(Textures::lives, "Resources/heart.png");
    textureHolder.load(Textures::pauseOn, "Resources/pauseOn.png");
    textureHolder.load(Textures::pauseOff, "Resources/pauseOff.png");
    textureHolder.load(Textures::audioOff, "Resources/audioOff.png");
    textureHolder.load(Textures::audioOn, "Resources/audioOn.png");
    textureHolder.load(Textures::musicOff, "Resources/musicOff.png");
    textureHolder.load(Textures::musicOn, "Resources/musicOn.png");
    textureHolder.load(Textures::warriorLvlOne, "Resources/enemyOne.png");
    textureHolder.load(Textures::warriorLvlTwo, "Resources/enemy.png");
    textureHolder.load(Textures::towerOneTop, "Resources/towerOneTop.png");
    textureHolder.load(Textures::towerTwoTop, "Resources/towerTopTwo.png");
    textureHolder.load(Textures::towerOneBase, "Resources/towerOneBase.png");
    textureHolder.load(Textures::towerTwoBase, "Resources/towerBaseTwo.png");
    textureHolder.load(Textures::bulletOne, "Resources/bulletOne.png");
    textureHolder.load(Textures::bulletTwo, "Resources/bulletTwo.png");
}


void Game::update(sf::Time frameTime) {
    stateManager.update(frameTime);
}

void Game::draw() {
    window.clear(sf::Color(210, 210, 210));
    stateManager.draw();
    window.display();
}

void Game::registerStates() {
    stateManager.registerState<GameState>(States::ID::Game);
}