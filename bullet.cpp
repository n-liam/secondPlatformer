#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <assert.h>

#include "headers/lists.h"
#include "headers/entity.h"

#include "headers/bullet.h"





void Bullet::fire(int x, int y, int direction)
{
	if (!m_isActive)
	{
		(*this).setPosition(x,y);
	}
	m_direction = direction;
	m_isActive = true;
}

void Bullet::travel()
{
	m_activeTimer +=1;
	(*this).move(m_direction, 0);
	if (m_activeTimer > 200)
	{	
		m_activeTimer = 0;
		m_isActive = false;
	}
}

void Bullet::deactivate()
{
	m_isActive = false;
	
}