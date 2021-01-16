//
//  main.cpp
//  Aircraft Shot Game
//
//  Created by Alastor on 2020/10/21.
//

#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <math.h>
#include <cstdlib>
#include <vector>
#include "Menuu.h"
#include "diff.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <SFML\Audio\Music.hpp>
using namespace sf;
int page_number;
using namespace std;
class Bullet
{
public:
    Sprite shape;

    Bullet(Texture* texture, Vector2f pos)
    {
        this->shape.setTexture(*texture);

        this->shape.setScale(0.07f, 0.07f);

        this->shape.setPosition(pos);
    }
};

class Player
{
public:
    Sprite shape;
    Texture* texture;
    int HP;
    int HPMax;

    std::vector <Bullet> bullets;

    Player(Texture* texture)
    {
        this->HPMax = 10;
        this->HP = this->HPMax;

        this->texture = texture;
        this->shape.setTexture(*texture);

        this->shape.setScale(0.1f, 0.1f);
    }
    ~Player() {}
};

class Enemy_easy
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemy_easy(Texture* texture, Vector2u windowSize)
    {
        this->HPMax = 1;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);

        this->shape.setScale(0.1f, 0.1f);

        this->shape.setPosition(rand() % (int)(windowSize.x - this->shape.getGlobalBounds().width), this->shape.getGlobalBounds().height);
    }
    ~Enemy_easy() {}
};
class Enemy_medium
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemy_medium(Texture* texture, Vector2u windowSize)
    {
        this->HPMax = rand() % 2 + 1;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);

        this->shape.setScale(0.1f, 0.1f);

        this->shape.setPosition(rand() % (int)(windowSize.x - this->shape.getGlobalBounds().width), this->shape.getGlobalBounds().height);
    }
    ~Enemy_medium() {}
};
class Enemy_hard
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemy_hard(Texture* texture, Vector2u windowSize)
    {
        this->HPMax = rand() % 3 + 1;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);

        this->shape.setScale(0.1f, 0.1f);

        this->shape.setPosition(rand() % (int)(windowSize.x - this->shape.getGlobalBounds().width), this->shape.getGlobalBounds().height);
    }
    ~Enemy_hard() {}
};


void play() {

    RenderWindow window(VideoMode(800, 600), "SFML_Make_Manu");
    Menuu menu(800, 600);
    //music added
    Music music;
    int a = true;
    if (!music.openFromFile("Music/music.flac")) {
        std::cout << "error" << std::endl;
    }
    music.play();
    //music end
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();


            if (event.type == sf::Event::KeyReleased) {
                //close the window
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                    return;
                }
                if (event.key.code == sf::Keyboard::M) {
                    if (a == true) {
                        music.pause();
                        a = false;
                    }
                    else {
                        music.play();
                        a = true;
                    }
                    //music pause and start end
                }
                if (event.key.code == sf::Keyboard::Up) {
                    menu.moveUp();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    menu.moveDown();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return) {

                    if (menu.mainMenuPressed() == 0) {
                        window.close();
                        page_number = 0;

                    }
                    if (menu.mainMenuPressed() == 1) {
                        window.close();
                        page_number = 1;
                    }
                    if (menu.mainMenuPressed() == 2) {
                        window.close();
                        page_number = 2;
                    }
                }
            }
        }
        window.clear();
        menu.draw(window);
        window.display();
    }
    //diff level
    if (page_number == 0) {
        RenderWindow window(VideoMode(800, 600), "diff level");
        diff menu(800, 600);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();


                if (event.type == sf::Event::KeyReleased) {
                    //close the window
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                        return;
                    }

                    if (event.key.code == sf::Keyboard::Up) {
                        menu.moveUp();
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Down) {
                        menu.moveDown();
                        break;
                    }
                    if (event.key.code == sf::Keyboard::Return) {

                        if (menu.mainMenuPressed() == 0) {
                            window.close();
                            page_number = 3;

                        }
                        if (menu.mainMenuPressed() == 1) {
                            window.close();
                            page_number = 4;
                        }
                        if (menu.mainMenuPressed() == 2) {
                            window.close();
                            page_number = 5;
                        }
                    }
                }
            }
            window.clear();
            menu.draw(window);
            window.display();
        }

    }
    int score = 0;
    if (page_number == 3) {
        RenderWindow window_play(VideoMode(800, 600), "Spaceship action!", Style::Default);
        window_play.setFramerateLimit(60);


        //init text
        Font font;
        font.loadFromFile("Fonts/Dosis-Light.ttf");

        //init textures
        Texture playerTex;
        playerTex.loadFromFile("Textures/ship.png");

        //change enemy
        Texture enemyTex1;
        enemyTex1.loadFromFile("Textures/enemy1.png");

        Texture enemyTex2;
        enemyTex2.loadFromFile("Textures/enemy2.png");

        Texture enemyTex3;
        enemyTex3.loadFromFile("Textures/enemy3.png");
        //enemy change end

        //change bullet
        Texture bulletTex;
        bulletTex.loadFromFile("Textures/bullet1.png");

        Texture bulletTex2;
        bulletTex2.loadFromFile("Textures/bullet2.png");

        Texture bulletTex3;
        bulletTex3.loadFromFile("Textures/bullet3.png");

        Texture bulletTex4;
        bulletTex4.loadFromFile("Textures/bullet4.png");
        //UI init
        Text scoreText;
        scoreText.setFont(font);
        scoreText.setCharacterSize(20);
        scoreText.setFillColor(Color::White);
        scoreText.setPosition(10.f, 10.f);

        Text gameOverText;
        gameOverText.setFont(font);
        gameOverText.setCharacterSize(30);
        gameOverText.setFillColor(Color::Red);
        gameOverText.setPosition(100.f, window_play.getSize().y / 2);
        gameOverText.setString("GAME OVER!");

        //player init

        Player player(&playerTex);
        int shootTimer = 20;
        Text hpText;
        hpText.setFont(font);
        hpText.setCharacterSize(12);
        hpText.setFillColor(Color::White);

        //enemy init
        int enemySpawnTimer = 0;
        std::vector<Enemy_easy> enemies;
        Text ehpText;
        ehpText.setFont(font);
        ehpText.setCharacterSize(12);
        ehpText.setFillColor(Color::White);

        //Track whether the game is running
        bool paused = true;
        srand(time(NULL));
        while (window_play.isOpen()) {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window_play.close();
            }
            //Start the game
            if (Keyboard::isKeyPressed(Keyboard::Enter))
            {
                system("pause");
            }
            Event event;
            while (window_play.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window_play.close();
            }

            if (player.HP > 0) {
                //player
                if (Keyboard::isKeyPressed(Keyboard::W))
                    player.shape.move(0.f, -10.f);
                if (Keyboard::isKeyPressed(Keyboard::A))
                    player.shape.move(-10.f, 0.f);
                if (Keyboard::isKeyPressed(Keyboard::S))
                    player.shape.move(0.f, 10.f);
                if (Keyboard::isKeyPressed(Keyboard::D))
                    player.shape.move(10.f, 0.f);

                hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - ehpText.getGlobalBounds().height);
                hpText.setString(std::to_string(player.HP) + "/" + std::to_string(player.HPMax));


                //Collision with window
                if (player.shape.getPosition().x <= 0) //left
                    player.shape.setPosition(0.f, player.shape.getPosition().y);
                if (player.shape.getPosition().x >= window_play.getSize().x - player.shape.getGlobalBounds().width) //right
                    player.shape.setPosition(window_play.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
                if (player.shape.getPosition().y <= 0) //top
                    player.shape.setPosition(player.shape.getPosition().x, 0.f);
                if (player.shape.getPosition().y >= window_play.getSize().y - player.shape.getGlobalBounds().height) //bottom
                    player.shape.setPosition(player.shape.getPosition().x, window_play.getSize().y - player.shape.getGlobalBounds().height);

                //update controls
                if (shootTimer < 15)
                    shootTimer++;

                if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 15) {
                    int a = rand() % 4;
                    if (a == 0) {
                        player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
                    }
                    else if (a == 1) {
                        player.bullets.push_back(Bullet(&bulletTex2, player.shape.getPosition()));
                    }
                    else if (a == 2) {
                        player.bullets.push_back(Bullet(&bulletTex3, player.shape.getPosition()));
                    }
                    else if (a == 3) {
                        player.bullets.push_back(Bullet(&bulletTex4, player.shape.getPosition()));
                    }
                    shootTimer = 0;  //reset timer
                }

                //Bullets
                for (size_t i = 0; i < player.bullets.size(); i++)
                {
                    //move
                    player.bullets[i].shape.move(0.f, -10.f);

                    //out of window bounds
                    if (player.bullets[i].shape.getPosition().x > window_play.getSize().x)
                    {
                        player.bullets.erase(player.bullets.begin() + i);
                        break;
                    }
                    //enemy collision
                    for (size_t k = 0; k < enemies.size(); k++)
                    {
                        if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
                        {
                            if (enemies[k].HP <= 1) {
                                score += enemies[k].HPMax;
                                enemies.erase(enemies.begin() + k);
                            }
                            else
                                enemies[k].HP--; //ENEMY TAKE DAMAGE

                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                    }
                }




                //Enemy
                if (enemySpawnTimer < 25)
                    enemySpawnTimer++;

                //enemy spawn
                if (enemySpawnTimer >= 25) {
                    int a = rand() % 3;
                    if (a == 0) {
                        enemies.push_back(Enemy_easy(&enemyTex1, window_play.getSize()));
                    }
                    else if (a == 1) {
                        enemies.push_back(Enemy_easy(&enemyTex2, window_play.getSize()));
                    }
                    //one more
                    else {
                        enemies.push_back(Enemy_easy(&enemyTex3, window_play.getSize()));
                    }
                    enemySpawnTimer = 0; //rest timer
                }



                for (size_t i = 0; i < enemies.size(); i++) {
                    enemies[i].shape.move(0.f, 3.f);
                    if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
                    {
                        enemies.erase(enemies.begin() + i);
                        break;
                    }
                    if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) {
                        enemies.erase(enemies.begin() + i);
                        player.HP--;
                        break;//player take damage
                    }
                }

                //UI Update
                scoreText.setString("Score: " + std::to_string(score));
            }

            //draw
            window_play.clear();

            //player
            window_play.draw(player.shape);

            //bullets
            for (size_t i = 0; i < player.bullets.size(); i++) {
                window_play.draw(player.bullets[i].shape);
            }

            //enemy
            for (size_t i = 0; i < enemies.size(); i++) {
                ehpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));
                ehpText.setPosition(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y - ehpText.getGlobalBounds().height);
                window_play.draw(ehpText);
                window_play.draw(enemies[i].shape);
            }

            //UI
            window_play.draw(scoreText);
            window_play.draw(hpText);

            if (player.HP <= 0)
                window_play.draw(gameOverText);

            window_play.display();
        }
    }
    score = 0;
    if (page_number == 4) {
        RenderWindow window_play(VideoMode(800, 600), "Spaceship action!", Style::Default);
        window_play.setFramerateLimit(60);


        //init text
        Font font;
        font.loadFromFile("Fonts/Dosis-Light.ttf");

        //init textures
        Texture playerTex;
        playerTex.loadFromFile("Textures/ship.png");

        //change enemy
        Texture enemyTex1;
        enemyTex1.loadFromFile("Textures/enemy1.png");

        Texture enemyTex2;
        enemyTex2.loadFromFile("Textures/enemy2.png");

        Texture enemyTex3;
        enemyTex3.loadFromFile("Textures/enemy3.png");
        //enemy change end

        //change bullet
        Texture bulletTex;
        bulletTex.loadFromFile("Textures/bullet1.png");

        Texture bulletTex2;
        bulletTex2.loadFromFile("Textures/bullet2.png");

        Texture bulletTex3;
        bulletTex3.loadFromFile("Textures/bullet3.png");

        Texture bulletTex4;
        bulletTex4.loadFromFile("Textures/bullet4.png");


        //UI init
        Text scoreText;
        scoreText.setFont(font);
        scoreText.setCharacterSize(20);
        scoreText.setFillColor(Color::White);
        scoreText.setPosition(10.f, 10.f);

        Text gameOverText;
        gameOverText.setFont(font);
        gameOverText.setCharacterSize(30);
        gameOverText.setFillColor(Color::Red);
        gameOverText.setPosition(100.f, window_play.getSize().y / 2);
        gameOverText.setString("GAME OVER!");

        //player init

        Player player(&playerTex);
        int shootTimer = 20;
        Text hpText;
        hpText.setFont(font);
        hpText.setCharacterSize(12);
        hpText.setFillColor(Color::White);

        //enemy init
        int enemySpawnTimer = 0;
        std::vector<Enemy_medium> enemies;
        Text ehpText;
        ehpText.setFont(font);
        ehpText.setCharacterSize(12);
        ehpText.setFillColor(Color::White);

        //Track whether the game is running
        bool paused = true;
        srand(time(NULL));
        while (window_play.isOpen()) {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window_play.close();
            }
            //Start the game
            if (Keyboard::isKeyPressed(Keyboard::Return))
            {
                paused = false;
            }
            if (!paused)
            {
                Event event;
                while (window_play.pollEvent(event)) {
                    if (event.type == Event::Closed)
                        window_play.close();
                }
            }// End if(!paused)
            if (player.HP > 0) {
                //player
                if (Keyboard::isKeyPressed(Keyboard::W))
                    player.shape.move(0.f, -10.f);
                if (Keyboard::isKeyPressed(Keyboard::A))
                    player.shape.move(-10.f, 0.f);
                if (Keyboard::isKeyPressed(Keyboard::S))
                    player.shape.move(0.f, 10.f);
                if (Keyboard::isKeyPressed(Keyboard::D))
                    player.shape.move(10.f, 0.f);

                hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - ehpText.getGlobalBounds().height);
                hpText.setString(std::to_string(player.HP) + "/" + std::to_string(player.HPMax));


                //Collision with window
                if (player.shape.getPosition().x <= 0) //left
                    player.shape.setPosition(0.f, player.shape.getPosition().y);
                if (player.shape.getPosition().x >= window_play.getSize().x - player.shape.getGlobalBounds().width) //right
                    player.shape.setPosition(window_play.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
                if (player.shape.getPosition().y <= 0) //top
                    player.shape.setPosition(player.shape.getPosition().x, 0.f);
                if (player.shape.getPosition().y >= window_play.getSize().y - player.shape.getGlobalBounds().height) //bottom
                    player.shape.setPosition(player.shape.getPosition().x, window_play.getSize().y - player.shape.getGlobalBounds().height);

                //update controls
                if (shootTimer < 15)
                    shootTimer++;

                if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 15) {
                    int a = rand() % 4;
                    if (a == 0) {
                        player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
                    }
                    else if (a == 1) {
                        player.bullets.push_back(Bullet(&bulletTex2, player.shape.getPosition()));
                    }
                    else if (a == 2) {
                        player.bullets.push_back(Bullet(&bulletTex3, player.shape.getPosition()));
                    }
                    else if (a == 3) {
                        player.bullets.push_back(Bullet(&bulletTex4, player.shape.getPosition()));
                    }
                    shootTimer = 0;  //reset timer
                }

                //Bullets
                for (size_t i = 0; i < player.bullets.size(); i++)
                {
                    //move
                    player.bullets[i].shape.move(0.f, -10.f);

                    //out of window bounds
                    if (player.bullets[i].shape.getPosition().x > window_play.getSize().x)
                    {
                        player.bullets.erase(player.bullets.begin() + i);
                        break;
                    }
                    //enemy collision
                    for (size_t k = 0; k < enemies.size(); k++)
                    {
                        if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
                        {
                            if (enemies[k].HP <= 1) {
                                score += enemies[k].HPMax;
                                enemies.erase(enemies.begin() + k);
                            }
                            else
                                enemies[k].HP--; //ENEMY TAKE DAMAGE

                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                    }
                }




                //Enemy
                if (enemySpawnTimer < 25)
                    enemySpawnTimer++;

                //enemy spawn
                if (enemySpawnTimer >= 25) {
                    int a = rand() % 3;
                    if (a == 0) {
                        enemies.push_back(Enemy_medium(&enemyTex1, window_play.getSize()));
                    }
                    else if (a == 1) {
                        enemies.push_back(Enemy_medium(&enemyTex2, window_play.getSize()));
                    }
                    //one more
                    else {
                        enemies.push_back(Enemy_medium(&enemyTex3, window_play.getSize()));
                    }
                    enemySpawnTimer = 0; //rest timer
                }



                for (size_t i = 0; i < enemies.size(); i++) {
                    enemies[i].shape.move(0.f, 5.f);
                    if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
                    {
                        enemies.erase(enemies.begin() + i);
                        break;
                    }
                    if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) {
                        enemies.erase(enemies.begin() + i);
                        player.HP--;
                        break;//player take damage
                    }
                }

                //UI Update
                scoreText.setString("Score: " + std::to_string(score));
            }

            //draw
            window_play.clear();

            //player
            window_play.draw(player.shape);

            //bullets
            for (size_t i = 0; i < player.bullets.size(); i++) {
                window_play.draw(player.bullets[i].shape);
            }

            //enemy
            for (size_t i = 0; i < enemies.size(); i++) {
                ehpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));
                ehpText.setPosition(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y - ehpText.getGlobalBounds().height);
                window_play.draw(ehpText);
                window_play.draw(enemies[i].shape);
            }

            //UI
            window_play.draw(scoreText);
            window_play.draw(hpText);

            if (player.HP <= 0)
                window_play.draw(gameOverText);

            window_play.display();
        }
    }

    score = 0;
    if (page_number == 5) {
        RenderWindow window_play(VideoMode(800, 600), "Spaceship action!", Style::Default);
        window_play.setFramerateLimit(60);


        //init text
        Font font;
        font.loadFromFile("Fonts/Dosis-Light.ttf");

        //init textures
        Texture playerTex;
        playerTex.loadFromFile("Textures/ship.png");

        //change enemy
        Texture enemyTex1;
        enemyTex1.loadFromFile("Textures/enemy1.png");

        Texture enemyTex2;
        enemyTex2.loadFromFile("Textures/enemy2.png");

        Texture enemyTex3;
        enemyTex3.loadFromFile("Textures/enemy3.png");
        //enemy change end

        //change bullet
        Texture bulletTex;
        bulletTex.loadFromFile("Textures/bullet1.png");

        Texture bulletTex2;
        bulletTex2.loadFromFile("Textures/bullet2.png");

        Texture bulletTex3;
        bulletTex3.loadFromFile("Textures/bullet3.png");

        Texture bulletTex4;
        bulletTex4.loadFromFile("Textures/bullet4.png");


        //UI init
        Text scoreText;
        scoreText.setFont(font);
        scoreText.setCharacterSize(20);
        scoreText.setFillColor(Color::White);
        scoreText.setPosition(10.f, 10.f);

        Text gameOverText;
        gameOverText.setFont(font);
        gameOverText.setCharacterSize(30);
        gameOverText.setFillColor(Color::Red);
        gameOverText.setPosition(100.f, window_play.getSize().y / 2);
        gameOverText.setString("GAME OVER!");

        //player init

        Player player(&playerTex);
        int shootTimer = 20;
        Text hpText;
        hpText.setFont(font);
        hpText.setCharacterSize(12);
        hpText.setFillColor(Color::White);

        //enemy init
        int enemySpawnTimer = 0;
        std::vector<Enemy_hard> enemies;
        Text ehpText;
        ehpText.setFont(font);
        ehpText.setCharacterSize(12);
        ehpText.setFillColor(Color::White);

        //Track whether the game is running
        bool paused = true;
        srand(time(NULL));
        while (window_play.isOpen()) {
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window_play.close();
            }
            //Start the game
            if (Keyboard::isKeyPressed(Keyboard::Return))
            {
                paused = false;
            }
            if (!paused)
            {
                Event event;
                while (window_play.pollEvent(event)) {
                    if (event.type == Event::Closed)
                        window_play.close();
                }
            }// End if(!paused)
            if (player.HP > 0) {
                //player
                if (Keyboard::isKeyPressed(Keyboard::W))
                    player.shape.move(0.f, -10.f);
                if (Keyboard::isKeyPressed(Keyboard::A))
                    player.shape.move(-10.f, 0.f);
                if (Keyboard::isKeyPressed(Keyboard::S))
                    player.shape.move(0.f, 10.f);
                if (Keyboard::isKeyPressed(Keyboard::D))
                    player.shape.move(10.f, 0.f);

                hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - ehpText.getGlobalBounds().height);
                hpText.setString(std::to_string(player.HP) + "/" + std::to_string(player.HPMax));


                //Collision with window
                if (player.shape.getPosition().x <= 0) //left
                    player.shape.setPosition(0.f, player.shape.getPosition().y);
                if (player.shape.getPosition().x >= window_play.getSize().x - player.shape.getGlobalBounds().width) //right
                    player.shape.setPosition(window_play.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
                if (player.shape.getPosition().y <= 0) //top
                    player.shape.setPosition(player.shape.getPosition().x, 0.f);
                if (player.shape.getPosition().y >= window_play.getSize().y - player.shape.getGlobalBounds().height) //bottom
                    player.shape.setPosition(player.shape.getPosition().x, window_play.getSize().y - player.shape.getGlobalBounds().height);

                //update controls
                if (shootTimer < 15)
                    shootTimer++;

                if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 15) {
                    int a = rand() % 4;
                    if (a == 0) {
                        player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
                    }
                    else if (a == 1) {
                        player.bullets.push_back(Bullet(&bulletTex2, player.shape.getPosition()));
                    }
                    else if (a == 2) {
                        player.bullets.push_back(Bullet(&bulletTex3, player.shape.getPosition()));
                    }
                    else if (a == 3) {
                        player.bullets.push_back(Bullet(&bulletTex4, player.shape.getPosition()));
                    }
                    shootTimer = 0;  //reset timer
                }

                //Bullets
                for (size_t i = 0; i < player.bullets.size(); i++)
                {
                    //move
                    player.bullets[i].shape.move(0.f, -10.f);

                    //out of window bounds
                    if (player.bullets[i].shape.getPosition().x > window_play.getSize().x)
                    {
                        player.bullets.erase(player.bullets.begin() + i);
                        break;
                    }
                    //enemy collision
                    for (size_t k = 0; k < enemies.size(); k++)
                    {
                        if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
                        {
                            if (enemies[k].HP <= 1) {
                                score += enemies[k].HPMax;
                                enemies.erase(enemies.begin() + k);
                            }
                            else
                                enemies[k].HP--; //ENEMY TAKE DAMAGE

                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                    }
                }




                //Enemy
                if (enemySpawnTimer < 25)
                    enemySpawnTimer++;

                //enemy spawn
                if (enemySpawnTimer >= 25) {
                    int a = rand() % 3;
                    if (a == 0) {
                        enemies.push_back(Enemy_hard(&enemyTex1, window_play.getSize()));
                    }
                    else if (a == 1) {
                        enemies.push_back(Enemy_hard(&enemyTex2, window_play.getSize()));
                    }
                    //one more
                    else {
                        enemies.push_back(Enemy_hard(&enemyTex3, window_play.getSize()));
                    }
                    enemySpawnTimer = 0; //rest timer
                }



                for (size_t i = 0; i < enemies.size(); i++) {
                    enemies[i].shape.move(0.f, 8.f);
                    if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
                    {
                        enemies.erase(enemies.begin() + i);
                        break;
                    }
                    if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds())) {
                        enemies.erase(enemies.begin() + i);
                        player.HP--;
                        break;//player take damage
                    }
                }

                //UI Update
                scoreText.setString("Score: " + std::to_string(score));
            }

            //draw
            window_play.clear();

            //player
            window_play.draw(player.shape);

            //bullets
            for (size_t i = 0; i < player.bullets.size(); i++) {
                window_play.draw(player.bullets[i].shape);
            }

            //enemy
            for (size_t i = 0; i < enemies.size(); i++) {
                ehpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));
                ehpText.setPosition(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y - ehpText.getGlobalBounds().height);
                window_play.draw(ehpText);
                window_play.draw(enemies[i].shape);
            }

            //UI
            window_play.draw(scoreText);
            window_play.draw(hpText);

            if (player.HP <= 0)
                window_play.draw(gameOverText);

            window_play.display();
        }
    }

    ifstream fileIn("leaderboard.txt");
    vector<string> contents;
    string line;
    while (getline(fileIn, line)) {
        contents.push_back(line);
    }
    fileIn.close();
    vector<int> leader;
    vector<int> temp;
    for (int i = 0; i < 3; i++) {
        temp.push_back(atoi(contents.at(i).c_str()));
    }
    if (score >= temp.at(0)) {
        if (score >= temp.at(1)) {
            if (score >= temp.at(2)) {
                leader.push_back(temp.at(1));
                leader.push_back(temp.at(2));
                leader.push_back(score);
            }
            else {
                leader.push_back(temp.at(1));
                leader.push_back(score);
                leader.push_back(temp.at(2));
            }
        }
        else {
            leader.push_back(score);
            leader.push_back(temp.at(1));
            leader.push_back(temp.at(2));
        }
    }
    else {
        leader = temp;
    }
    ofstream fileOut("leaderboard.txt");
    for (int myscore : leader) {
        fileOut << myscore << endl;
    }
    fileOut.close();
    //Tutorials, Zhenyue's code should be here
    if (page_number == 1) {
        RenderWindow window_tutorial(VideoMode(800, 550), "Tutorial", Style::Default);
        window_tutorial.setFramerateLimit(60);
        Texture texture;
        texture.loadFromFile("Textures/tutorial.png");
        Font font;
        sf::Sprite sprite;
        sprite.setTexture(texture);
        while (window_tutorial.isOpen()) {

            Event _event;
            while (window_tutorial.pollEvent(_event)) {
                if (_event.type == sf::Event::Closed) {

                    window_tutorial.close();

                }
            }
            if (_event.key.code == sf::Keyboard::Escape) {
                window_tutorial.close();
                return;
            }

            window_tutorial.clear();

            window_tutorial.draw(sprite);

            window_tutorial.display();

        }

        // return 0;
    }
    //Leaderboard, Feifan and Tom's code should be here

    if (page_number == 2) {
        Text scoretext1;
        Text scoretext2;
        Text scoretext3;
        Text scoreText;
        RenderWindow window_leaderboard(VideoMode(750, 510), "leaderBoard", Style::Default);
        ifstream text;
        text.open("leaderboard.txt");
        vector<string> scores;
        string str;
        while (!(text.eof())) {
            while (std::getline(text, str))
            {
                scores.push_back(str);
            }
        }
        text.close();
        while (window_leaderboard.isOpen()) {
            Event _event;
            Font font;
            font.loadFromFile("Fonts/Dosis-Light.ttf");
            scoretext1.setFont(font);
            scoretext2.setFont(font);
            scoretext3.setFont(font);

            scoretext1.setString("First place: " + scores[2]);
            scoretext2.setString("Second place: " + scores[1]);
            scoretext3.setString("Third place: " + scores[0]);

            scoretext1.setCharacterSize(60);
            scoretext1.setFillColor(sf::Color::Red);
            scoretext1.setStyle(sf::Text::Bold | sf::Text::Underlined);
            scoretext1.setPosition(170.f, 100.f);

            scoretext2.setCharacterSize(60);
            scoretext2.setFillColor(sf::Color::Red);
            scoretext2.setStyle(sf::Text::Bold | sf::Text::Underlined);
            scoretext2.setPosition(270.f, 200.f);

            scoretext3.setCharacterSize(60);
            scoretext3.setFillColor(sf::Color::Red);
            scoretext3.setStyle(sf::Text::Bold | sf::Text::Underlined);
            scoretext3.setPosition(370.f, 300.f);

            while (window_leaderboard.pollEvent(_event)) {
                if (_event.type == sf::Event::Closed) {

                    window_leaderboard.close();
                    return;
                }

            }
            if (_event.key.code == sf::Keyboard::Escape) {
                window_leaderboard.close();
                return;
            }
            window_leaderboard.clear();

            window_leaderboard.draw(scoretext1);
            window_leaderboard.draw(scoretext2);
            window_leaderboard.draw(scoretext3);

            window_leaderboard.display();
        }
        return;
    }




    return;
}
int main() {
    while (true) {
        play();
    }
}
