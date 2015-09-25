#ifndef CHARACTER_H
#define CHARACTER_H

	class Character: public Entity
	{
	
		private:
			int m_upDownVelocity;
			int m_rightLeftVelocity;
			
			bool m_justJumped;
			bool m_isOnLadder;

			int m_hitPoints;
			bool m_dead;
			int m_deathTimer;
			
			
			
			
		public:
			
			Character()
			{
		
				m_upDownVelocity = 0;
				m_rightLeftVelocity = 0;
				m_justJumped = false;
				m_isOnLadder = false;
				
				m_dead = false;
				m_hitPoints = 100;
				m_deathTimer = 0;
			}
			
			void ladderCheck(Ladder ladder);
			
			void ladderMovement();
			void gravity();
			void movement();
			void friction();
			void jump();
			
			void physics();
			
			int getVelUD() { return m_upDownVelocity;}
			void setVelUD(int value) { m_upDownVelocity = value;}
			
			bool isOnLadder() {return m_isOnLadder;}
			
			void damage(int value){ m_hitPoints -= value; }
			void heal( int value) { m_hitPoints +=value;}
			void setHP(int value) { m_hitPoints = value;}
	
			void die() { (*this).setPosition( -100,-100); m_dead = true; }
			
			
			
			
		
	};
	


#endif