#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800,600}), "RPG");
    sf::CircleShape shape(50.0f, 8);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(100,100));
    shape.setOutlineThickness(1);
    
    while(window.isOpen()){
//------------------------------UPDATE-------------------------------
       while(const std::optional event= window.pollEvent()){
            if(event->is<sf::Event::Closed>())
                window.close();
        }
//------------------------------UPDATE-------------------------------
       

//------------------------------DRAW-------------------------------
       window.clear();
       window.draw(shape);
       window.display();
    }
//------------------------------DRAW-------------------------------
    return 0;
}