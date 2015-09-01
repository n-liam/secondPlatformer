#ifndef DECLARATIONS_H
#define DECLARATIONS_H


namespace Declared
{

	
	Character whiteDot;
	Entity	collidable;

	
	
	
	
	
	
	
	void setThings()
	{
		sf::Texture texture;
		texture.loadFromFile("sprites/whiteDot.png");
		whiteDot.setTexture(texture);
		whiteDot.scale(25,25);
		whiteDot.setPosition(250,20);
		
		collidable.setTexture(texture);
		collidable.setColor(sf::Color::Red);
		collidable.scale(400,20);
		collidable.setPosition(100,400);
		
		
		
	}
	
	
	
	
	
	void collision(Entity &movable, Entity &nonMovable)
	{
		if( movable.didCollideWith(nonMovable) )
		{
		
			int x_mov = movable.getPosition().x;
			int y_mov = movable.getPosition().y;
			int height_mov = movable.getGlobalBounds().height;
			int length_mov = movable.getGlobalBounds().width;
			
			
			
			int x_nonMov = nonMovable.getPosition().x;
			int y_nonMov = nonMovable.getPosition().y;
			int height_nonMov = nonMovable.getGlobalBounds().height;
			int length_nonMov = nonMovable.getGlobalBounds().width;
			
			int x_dif = (x_mov) - (x_nonMov);
			int y_dif = (y_mov+height_mov) - (y_nonMov);
			
			if(x_dif<0){x_dif = -x_dif;}
			if(y_dif<0){y_dif = -y_dif;}
			
			if(x_dif<= y_dif)
			{
				movable.move(0,y_dif);
			}
			else
			{
				movable.move(x_dif,0);
				
			}
			
			
		
		}
		
		
		
		//std::cout<<"("<<height_mov<<","<<length_mov<<")\n";
		//std::cout<<"("<<x_nonMovable<<","<<y_nonMovable<<")";
		
		
	}
	
	
	
}







#endif