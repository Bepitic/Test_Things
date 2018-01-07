#ifndef __Colisionable_HPP__
#define __Colisionable_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>
class Colisionable{
    public:
        Colisionable(int x, int y): pos_x(x), pos_y(y) { }
        
#ifdef _Debug_
        virtual void draw( sf::RenderWindow* window) { }

        virtual void estaColisionado(bool isCol);
#endif          
        float pos_x;
        float pos_y;

};

#endif
