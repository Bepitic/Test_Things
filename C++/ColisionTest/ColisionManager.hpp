#ifndef __ColisionManager_hpp__
#define __ColisionManager_hpp__

#include <math.h>
#include "Colisionable.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class ColisionManager{

    public:
        void addColisionable(Colisionable* col){
            v_Colisionables.push_back(col);

        }
        
        void draw(sf::RenderWindow* window){
            for(auto col : v_Colisionables){
#ifdef _Debug_
                col->draw(window);
#endif
            }
        }
        void colisionan(){
        
            for(unsigned i = 0; i < v_Colisionables.size(); ++i)
                for(unsigned j = v_Colisionables.size() -1; j > i ; --j){
                    bool c = areColided(v_Colisionables[i],v_Colisionables[j]);
                    v_Colisionables[i]->estaColisionado(c);
                }
        }

    private:
        std::vector<Colisionable*> v_Colisionables;
        bool areColided(Circulo* a, Circulo* b){
            return( abs( b->pos_x - a->pos_x ) * abs( b->pos_x - a->pos_x ) + abs( b->pos_y - a->pos_y ) * abs( b->pos_y - a->pos_y ) < ( (a->radio + b->radio) * (a->radio + b->radio) ) );
        }
};

#endif
