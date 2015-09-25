#ifndef BULLET_H
#define BULLET_H

class Bullet: public Entity
{
	private:
		int m_damage;
		bool m_isActive;
		int m_direction;
		int m_activeTimer;
		
		
	public:
		Bullet(int number = 10)
		{
			m_isActive = false;
			m_damage = number;
			m_activeTimer = 0;
		}


	
		
		void fire( int x, int y, int direction);
		
		void travel();
		void deactivate();
		
		bool isActive() {return m_isActive;}
		int damage() { (*this).setPosition(-100,-100);return m_damage;}


};





class BulletList: public List
{
	public:
		Bullet *m_list [40];
	
		void add(Bullet* address)
		{
			m_list[ m_index ] = address;
			m_index++;
			assert( m_index <= 40 );
		}
	
	
};

#endif