#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <assert.h>

#include "headers/lists.h"
#include "headers/entity.h"
#include "headers/ladder.h"
#include "headers/character.h"




void Character::ladderMovement() 
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
	{
		(*this).move(0,-3);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
	{
		(*this).move(0,3);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
	{
		m_isOnLadder = false;
	}
	
}

void Character::ladderCheck(Ladder ladder)
{
	if ( (*this).didCollideWith(ladder) )
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
		{
			
			m_isOnLadder = true;
			m_upDownVelocity = 0;
			
			m_justJumped = false;
		}
		
	}
	else 
	{
		m_isOnLadder = false;
	}
	
	if ( m_isOnLadder)
	{
		(*this).ladderMovement();
	}
	
}





void Character::gravity()
{
	
	int accel = 1;
	int terminalVel = 3;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
	{
		terminalVel = 9;
	}
	m_upDownVelocity += accel;
	if (m_upDownVelocity >terminalVel ) {m_upDownVelocity = terminalVel;}
	
	(*this).move(0, m_upDownVelocity);

	//The up down velocity gets reset every time the object is moved up to resolve collision. 
	// i.e every time it hits the floor. This is done in the Declaration::colision function
}




void Character::movement()
{
	
	int accel = 3;
	
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
	{

		m_rightLeftVelocity += accel;
		if (m_rightLeftVelocity >4){m_rightLeftVelocity =4;};
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
	{
		m_rightLeftVelocity -= accel;
		if (m_rightLeftVelocity <-4){m_rightLeftVelocity =-4;};
	}
	
	
	(*this).move(m_rightLeftVelocity,0);

}


void Character::friction()
{ 
	float frictCoeff =1.5;
	if (m_rightLeftVelocity >0 ) { m_rightLeftVelocity -=frictCoeff ;}
	else if (m_rightLeftVelocity <0) { m_rightLeftVelocity +=frictCoeff;}
}


void Character::jump()
{
	//std::cout<< " "<<m_upDownVelocity;
	
	// JUMP NEEDS TO HAPPEN BEFORE GRAVITY, OTHERWISE THE UD VEL WILL NOT BE ZERO WHEN THE OBJECT
	// IS IN CONTACT WITH THE FLOOR
	int jumpSpeed = 12;
	
	if (m_upDownVelocity == 0 && !m_justJumped) 
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
		{
			m_upDownVelocity -= jumpSpeed;
			m_justJumped = true;
	
		}
	}
	
	// As soon as we start falling again, the jump buffer is reset. This prevents chaining jumps.
	// With certain accel from gravity, there is an instant of 0 udvel at the apex of the jump. 
	// at this time another jump could be made. the justJumped prevents this.
	if ( m_upDownVelocity > 0 )
	{
		m_justJumped = false;
	}

}


void Character::physics()
{ 
/// Note that ladder movement occurs in the ladder check phase
	if (!m_isOnLadder) 
	{
		(*this).movement();
		(*this).friction();
		(*this).jump();
		(*this).gravity();
	}	
	if (m_hitPoints == 0)
	{
		(*this).die();
		m_hitPoints = 100;
	}
	if ( m_dead)
	{
		m_deathTimer +=1;
	}
	if ( m_deathTimer >=100)
	{
		(*this).setPosition( 100, 100);
		m_deathTimer = 0;
		m_dead = false;
	}
	
}

