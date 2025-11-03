#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800,600}), "RPG");
    
    sf::Texture playerTexture; 
    sf::Sprite playerSprite(playerTexture);
    playerSprite.scale(sf::Vector2f(3, 3));
    float playerSpd= 0.03;

    if(!playerTexture.loadFromFile("assets/player/texture/playersheet.png")){
        std::cout << "failed to load";
    }

    int xIndex= 0;
    int yIndex= 0;
    playerSprite.setTextureRect(sf::IntRect(sf::Vector2i(xIndex*16,yIndex*16), sf::Vector2i(16, 16)));

    while(window.isOpen()){
//------------------------------UPDATE-------------------------------
        while(const std::optional event= window.pollEvent()){
            if(event->is<sf::Event::Closed>())
                window.close();
        }
//------------------------------UPDATE-------------------------------
        sf::Vector2f moveDir(0.0f, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            moveDir.y -= playerSpd;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            moveDir.y += playerSpd;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            moveDir.x -= playerSpd;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            moveDir.x += playerSpd;
        }
        playerSprite.move(moveDir);
//------------------------------DRAW-------------------------------
       window.clear();
       window.draw(playerSprite);
       window.display();
    }
//------------------------------DRAW-------------------------------
    return 0;
}