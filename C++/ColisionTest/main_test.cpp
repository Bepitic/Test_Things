#define _Debug_
#include <iostream>
#include "Circulo.hpp"
#include "ColisionManager.hpp"
#include <SFML/Graphics.hpp>

int main(){

    Circulo col = Circulo(100,100,100);
    Circulo col1 = Circulo(110,100,11);
    ColisionManager cManager = ColisionManager();
    cManager.addColisionable(&col);
    sf::RenderWindow window;
    sf::Clock clock;
    //sf::Window window(sf::VideoMode(800, 600), "My window");
    window.create(sf::VideoMode(800,600),"");// , sf::Style::None);
    window.setVerticalSyncEnabled(true);
    while(window.isOpen())
    {
    	sf::Time elapsed = clock.restart();
    	float dt = elapsed.asSeconds();

        window.clear(sf::Color::Blue);
        cManager.draw(&window);
        window.display();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;

}
