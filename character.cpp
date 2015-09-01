#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


#include "headers/entity.h"
#include "headers/character.h"
#include "headers/radarDot.h"



void Character::gravity()
{
	
	int accel = 5;
	int terminalVel = 20;
	

	(*this).move( 0, (*this).getVelUD() +accel);
	if( (*this).getVelUD() >=terminalVel )
	{
		(*this).setVelUD(terminalVel);
	}
	
	
	
}

