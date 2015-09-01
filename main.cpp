#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


#include "headers/entity.h"
#include "headers/character.h"
#include "headers/radarDot.h"

#include "headers/declarations.h"


int main()
{
	
	sf::RenderWindow window( sf::VideoMode(800,800), "main");
    //window.setKeyRepeatEnabled(true);
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
	
	
	
	
	sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));   
	
	Declared::setThings();

	
	while( window.isOpen())
    { 
   
        
        sf::Event event;
        while (window.pollEvent(event) ) 
        {
            
            
            if (event.type== sf::Event::Closed)
                {window.close();}

        }

		
		//////////////////////////////////////////
		// Keyboard Inputs
		//////////////////////////////////////////
		using namespace Declared;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
		{
			Declared::whiteDot.move(-2,0);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
		{
			Declared::whiteDot.move(2,0);
		}
		
		whiteDot.gravity();
		
		
		
		window.clear(sf::Color::Black);
		view.setCenter(whiteDot.getPosition());
		window.setView(view);
		
		
		window.draw(Declared::whiteDot);
		window.draw(collidable);
		
		collision(whiteDot, collidable);
		
		window.display();
		
	}
	
	return 0;
}