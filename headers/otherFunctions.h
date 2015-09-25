#ifndef OTHERFUNCTIONS_H
#define OTHERFUNCTIONS_H


///////////////////////////////////////////////////////////
/// COLLISION
/////////////////////////////////////////////////////////
void collision(Character &movable, Entity &nonMovable)
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
			
			int upCounter = 0;
			int downCounter = 0;
			int leftCounter = 0;
			int rightCounter =0;
			/// One loop for each direction. then choose the shortest way out of the object
			
			/// Instead of using while loops, you can just calculate values using math. 
			/// Consider doing this at some point just to make code faster.
			//up
			while (movable.didCollideWith(nonMovable) )
			{
				movable.move(0,-1);
				upCounter++;
			}
			movable.move(0,upCounter);
			
			//down
			while (movable.didCollideWith(nonMovable) )
			{
				movable.move(0,1);
				downCounter++;
			}
			movable.move(0,-downCounter);
			
			//right
			while (movable.didCollideWith(nonMovable) )
			{
				movable.move(1,0);
				rightCounter++;
			}
			movable.move(-rightCounter,0);
			
			//left
			while (movable.didCollideWith(nonMovable) )
			{
				movable.move(-1,0);
				leftCounter++;
			}
			movable.move(leftCounter,0);
			
			char direction ='D';
			int minDist = downCounter;
			
			
			if (rightCounter < minDist) { direction = 'R'; minDist = rightCounter;}
			if (leftCounter < minDist) { direction = 'L'; minDist = leftCounter;}
			if (upCounter < minDist) { direction = 'U'; minDist = upCounter; movable.setVelUD(0); }
			
			
			switch(direction) 
			{
				case 'U':
					movable.move(0,-minDist);
					break;
				case 'D':
					movable.move(0,minDist);
					break;
				case 'R':
					movable.move(minDist, 0);
					break;
				case 'L':
					movable.move(-minDist,0);
					break;

			}
			
			
			
			
			
		
		}
		
		
		
		//std::cout<<"("<<height_mov<<","<<length_mov<<")\n";
		//std::cout<<"("<<x_nonMovable<<","<<y_nonMovable<<")";
		
		
	}
	
	
	
	
	
	
	
	
//////////////////////////////////////////////////
/// VIEW CONTROL
/// there are vars that depend on global map dims here.
///////////////////////////////////////////////	
	
	void viewControl(sf::View &view, Character character)
	{
		// the character position
		int x_pos = character.getPosition().x;
		int y_pos = character.getPosition().y;
		
		// the window dimensions
		int x_size = 1200;
		int y_size = 900;
		
		// the full map dimensions
		int x_mapDim = 1800;
		int y_mapDim =900;
		
		
		// initiate the view position
		int x_view = x_pos;
		int y_view = y_pos;
		
		
		
		if ( x_pos + x_size/2  > x_mapDim ) { x_view = x_mapDim - x_size/2; }
		if ( x_pos - x_size/2 < 0 )	{ x_view = x_size/2; }
		
		if ( y_pos + y_size/2  > y_mapDim ) { y_view = y_mapDim - y_size/2; }
		if ( y_pos - y_size/2 < 0 )	{ y_view = y_size/2; }
		
		view.setCenter(x_view, y_mapDim/2);
		
		
	}
	
	
	
	
	
	





#endif