#ifndef SHAWPI_H
#define SHAWPI_H

class Shawpi: public Entity
{
	private:
		sf::Texture texture;
		
		bool m_isMoving;
		bool m_isAttacking;
		bool m_isAlive;
		int m_team;
		int m_yRange;
		int m_xRange;
		int m_directionToAttack;
		
		int m_floatCounter;
		int m_attackBuffer;
		
	public:
		BulletList m_bulletList;
		Bullet m_bullet;
		Bullet m_bullet2;
		Bullet m_bullet3;
		Bullet m_bullet4;
		
		Shawpi(int team) //-1 for right, 1 for left (i.e. the directino the shawpi will move
		{
			texture.loadFromFile("sprites/whiteDot.png");
			
			m_floatCounter =0;
			m_team  = team;
			m_isMoving = false;
			m_isAttacking = false;
			m_isAlive = false;
			m_xRange = 100;
			m_yRange = 40;
			m_attackBuffer = 0;
			
			m_bulletList.add(&m_bullet);
			m_bulletList.add(&m_bullet2);
			m_bulletList.add(&m_bullet3);
			m_bulletList.add(&m_bullet4);
			for (int iii=0; iii< m_bulletList.index(); iii++)
			{
				(*m_bulletList.m_list[iii]).setTexture(texture);
				(*m_bulletList.m_list[iii]).setColor(sf::Color::Magenta);
				(*m_bulletList.m_list[iii]).setScale(5,5);
			}
		}
		void movePhase();
		void attackCheck(Entity entity);
		void attack(int direction);
		void activate();
	
};





class ShawpiList: public List
{
	public:
		Shawpi *m_list [40];
	
		void add(Shawpi* address)
		{
			m_list[ m_index ] = address;
			m_index++;
			assert( m_index <= 40);
		}
	
	
};






#endif