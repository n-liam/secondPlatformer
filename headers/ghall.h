#ifndef GHALL_H
#define GHALL_H


class Ghall: public Character
{
	
	private:
		int m_hitPoints;
		bool m_dead;
		
	public:
		
		Ghall()
		{
			m_dead = false;
			m_hitPoints = 100;
		}
		void damage(int value){ m_hitPoints -= value; }
		void heal( int value) { m_hitPoints +=value;}
	
		void die() { (*this).setPosition( -100,-100); m_dead = true; }
}




#endif