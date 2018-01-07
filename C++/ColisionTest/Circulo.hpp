#ifndef __Circulo_HPP__
#define __Circulo_HPP__

#include "Colisionable.hpp"
#include <SFML/Graphics.hpp>

class Circulo : public Colisionable {
  
    public:  
        Circulo(float x, float y, float r): Colisionable(x,y), radio(r) {
            
            Colisionable(x,y);
        
#ifdef _Debug_
            s_circulo = sf::CircleShape(r);
            s_circulo.setPosition(x,y);
            s_circulo.setFillColor(sf::Color::Transparent);
            s_circulo.setOutlineColor(sf::Color::White);
            s_circulo.setOutlineThickness(1.0);
#endif        
        }
        
        float radio;
        
#ifdef _Debug_
        sf::CircleShape s_circulo;
        void draw( sf::RenderWindow* window){
            window->draw(s_circulo);
        }
        void estaColisionado(bool isCol){
        isCol ? s_circulo.setOutlineColor(sf::Color::Red) : s_circulo.setOutlineColor(sf::Color::White); 
        }
#endif        


};
#endif
