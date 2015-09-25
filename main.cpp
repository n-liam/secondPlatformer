#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <assert.h>

#include "headers/lists.h"
#include "headers/entity.h"
#include "headers/floor.h"
#include "headers/ladder.h"
#include "headers/character.h"




#include "headers/bullet.h"

#include "headers/shawpi.h"
#include "headers/factory.h"


#include "headers/declarations.h"

#include "headers/otherFunctions.h"


int main()
{
	using namespace Declared;
	sf::RenderWindow window( sf::VideoMode(1200,900), "main");
    //window.setKeyRepeatEnabled(true);
    //window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
	
	/*IntList list;
	int numb = 10;
	std::cout<< numb;
	
	list.add(numb);
	
	std::cout<< "\n"<< *list.m_list[0];
	*/
	
	
	sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));   
	
	setThings();
	

	


	
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
		
		/*
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
		{
			Declared::whiteDot.move(-2,0);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
		{
			Declared::whiteDot.move(2,0);
		}
		*/
		
	
		
		window.clear(sf::Color::Black);
		//view.setCenter(whiteDot.getPosition());
		viewControl(view, whiteDot);
		window.setView(view);
		
		//////////////
		/// LADDER CHECK (INCLUDES LADDER MOVEMENT)
		////////////////////
		whiteDot.ladderCheck(ladder);
		
		//////////////
		// PHYSICS
		/////////////
		whiteDot.physics();
		
		////////
		// COLLISION LOOPS ARE HERE
		////////////
		if( !whiteDot.isOnLadder() )
		{
			for( int iii=0; iii< gameBoundaries.index(); iii++)
			{
				collision(whiteDot, *gameBoundaries.m_list[iii] );
			}
			for( int iii=0; iii< gamePlatforms.index(); iii++)
			{
				collision(whiteDot, *gamePlatforms.m_list[iii] );
			}
		}
		
		
		//////////
		// DRAW LOOPS ARE HERE
		//////////
		
		for( int iii =0; iii< gamePlatforms.index(); iii++)
		{
			window.draw( *gamePlatforms.m_list[iii] );
		}
		for( int iii =0; iii< gameBoundaries.index(); iii++)
		{
			window.draw( *gameBoundaries.m_list[iii] );
		}
		window.draw(ladder);
		window.draw(Declared::whiteDot);
		
		/// REMEMBER TO CHANGE THIS STUFF. NEED TO PUT in fucntions, too much to write
		window.draw(shawpi);
		
		shawpi.attackCheck(whiteDot);
		shawpi.activate();
		
		for( int iii=0; iii< shawpi.m_bulletList.index(); iii++)
		{
			Bullet *bulletAddress = (shawpi.m_bulletList.m_list[iii]);
			if( (*bulletAddress).isActive() )
			{
				(*bulletAddress).travel();
				window.draw(*bulletAddress);
				if( (*bulletAddress).didCollideWith(whiteDot) )
				{
					whiteDot.damage( (*bulletAddress).damage() );
				}
			}
		}

		
		
		
		
		window.display();
		
	}
	
	return 0;
}

/*

cl main.cpp character.cpp bullet.cpp shawpi.cpp factory.cpp  /I SFML\SFML-2.3.1\include /link SFML\SFML-2.3.1\lib\sfml-graphics.lib SFML\SFML-2.3.1\lib\sfml-window.lib SFML\SFML-2.3.1\lib\sfml-system.lib
 
 */