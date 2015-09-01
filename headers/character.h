#ifndef CHARACTER_H
#define CHARACTER_H

	class Character: public Entity
	{
	
		private:
			int m_upDownVelocity;
			int m_rightLeftVelocity;
			
			
			
		public:
			
			Character()
			{
				m_upDownVelocity = 0;
			}
			
			void gravity();
			void movement();
			
			int getVelUD() { return m_upDownVelocity;}
			void setVelUD(int value) { m_upDownVelocity = value;}
			
		
	};
	


#endif