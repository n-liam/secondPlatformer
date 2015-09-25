#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <assert.h>

#include "headers/lists.h"
#include "headers/entity.h"




#include "headers/bullet.h"
#include "headers/shawpi.h"




void Shawpi::movePhase() 
{
	m_floatCounter +=1;
	if ( (m_floatCounter%5 ==0 && m_floatCounter <=15) ||m_floatCounter ==1 )
	{
		(*this).move(0,1);
	}
	
	if (m_floatCounter%5==0 && m_floatCounter >15)
	{
		(*this).move(0,-1);
	}
	if (m_floatCounter >=39) {m_floatCounter =0;}
	
	if (m_floatCounter%3 == 0)
	{
		(*this).move(m_team,0);
	}
}



void Shawpi::attack(int direction)
{
	if (m_attackBuffer >50) {m_attackBuffer = 0;}
	int x = (*this).getPosition().x;
	int y = (*this).getPosition().y;
	if( !m_bullet.isActive() && m_attackBuffer ==0 )
	{
		m_bullet.fire(x,y,direction);
	}
	else if (!m_bullet2.isActive() && m_attackBuffer==0 )
	{
		m_bullet2.fire(x,y,direction);
	}
	else if (!m_bullet3.isActive() && m_attackBuffer==0 )
	{
		m_bullet3.fire(x,y,direction);
	}
	else if (!m_bullet4.isActive() && m_attackBuffer==0 )
	{
		m_bullet4.fire(x,y,direction);
	}
	m_attackBuffer++;
	
}

void Shawpi::attackCheck( Entity entity)
{
	int x_this = (*this).getPosition().x;
	int y_this = (*this).getPosition().y;
	int x_ent = entity.getPosition().x;
	int y_ent = entity.getPosition().y;
	
	if ( (abs( x_this - x_ent) <= m_xRange ) && (abs( y_this - y_ent) <= m_yRange) ) 
	{
		
			
			m_isAttacking = true;
			if( x_this >= x_ent )
			{
					m_directionToAttack = -1;
			}
			else
			{
					m_directionToAttack = 1;
			}
			
		
	}
	else
	{
		
		m_isAttacking = false;
	}
	
	
}

void Shawpi::activate()
{
	if (m_isAttacking)
	{
		(*this).attack(m_directionToAttack);
	}
	else
	{
		(*this).movePhase();
	}
}




