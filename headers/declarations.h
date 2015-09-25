#ifndef DECLARATIONS_H
#define DECLARATIONS_H


namespace Declared
{

	
	EntityList gamePlatforms;
	Entity lplat1;
	Entity lplat2;
	Entity lplat3;
	Entity lplat4;
	Entity lplat5;
	Entity lplat6;
	Entity lplat7;
	Entity lplat8;
	Entity lplat9;
	Entity lplat10;
	Entity lplat11;
	Entity lplat12;
	Entity lplat13;
	Entity lplat14;
	Entity lplat15;


	
	
	
	
	void setPlatformsLeft()
	{
	
		sf::Texture texture;
		texture.loadFromFile("sprites/whiteDot.png");
		
	
		gamePlatforms.add(&lplat1);
		gamePlatforms.add(&lplat2);
		gamePlatforms.add(&lplat3);
		gamePlatforms.add(&lplat4);
		gamePlatforms.add(&lplat5);
		gamePlatforms.add(&lplat6);
		gamePlatforms.add(&lplat7);
		
		for( int iii=0; iii< gamePlatforms.index(); iii++)
		{
			(*gamePlatforms.m_list[iii]).setTexture(texture);
			(*gamePlatforms.m_list[iii]).setColor(sf::Color::Red);
		}
		lplat1.setScale(200,20);
		lplat1.setPosition(20,300);
		
		lplat2.setScale(400,20);
		lplat2.setPosition(20, 600);
		
		lplat3.setScale(40,20);
		lplat3.setPosition(200,360);
		
		lplat4.setScale(40,20);
		lplat4.setPosition(240,400);
		
		lplat5.setScale( 200,20);
		lplat5.setPosition(260,300);
		
		lplat6.setScale(80,20);
		lplat6.setPosition(440, 360);
		
		lplat7.setScale(360,20);
		lplat7.setPosition(500,300);
		
	}
		
		
	EntityList gameBoundaries;
	Entity gameFloor;	
	Entity gameWallLeft;
	Entity gameWallRight;	
	Entity gameCeiling;	
	Entity gameFloor2;
	void setBoundaries()
	{
		sf::Texture texture;
		texture.loadFromFile("sprites/whiteDot.png");
		
		gameBoundaries.add(&gameFloor);
		gameBoundaries.add(&gameWallLeft);
		gameBoundaries.add(&gameWallRight);
		gameBoundaries.add(&gameCeiling);
		gameBoundaries.add(&gameFloor2);
		for( int iii=0; iii< gameBoundaries.index(); iii++)
		{
			(*gameBoundaries.m_list[iii]).setTexture(texture);
			(*gameBoundaries.m_list[iii]).setColor(sf::Color::Cyan);
		}
		
		gameFloor.setScale(1800,20);
		gameFloor.setPosition(0,880);
		gameFloor2.setScale(1760,20);
		gameFloor2.setPosition(20,860);
		gameFloor2.setColor(sf::Color::Red);
		gameWallLeft.setScale(20,900);
		gameWallLeft.setPosition(0,0);
		gameWallRight.setScale(20,900);
		gameWallRight.setPosition(1780,0);
		gameCeiling.setScale(1800,20);
		gameCeiling.setPosition(0,0);
		
	}
	


	Ladder ladder;
	
	void setLadders() 
	{
		////////////////
		// TEXTURE LOAD
		//////
		sf::Texture texture;
		texture.loadFromFile("sprites/whiteDot.png");
		
		//////////////////
		//// LADDERS
		///////////////////////
		
		ladder.setTexture(texture);
		ladder.setScale(5, 500);
		ladder.setPosition(150,299);
		ladder.setColor(sf::Color::Green);
	}
	
	
	
	
	
	
	Shawpi shawpi(1);
	Character whiteDot;
	
	void setCharacters()
	{
		
		////////////////
		// TEXTURE LOAD
		//////
		sf::Texture texture;
		texture.loadFromFile("sprites/whiteDot.png");
		
		////////////////
		// CHARACTER SET UP
		///////////
		whiteDot.setTexture(texture);
		whiteDot.scale(15,15);
		whiteDot.setPosition(250,20);
		
		/////////////////////////////////////////////////////////////////
		/////////////////////
		// THIS STUFF NEEDS TO BE REMOVED, HERE FOR TESTS ONLY
		shawpi.setTexture(texture);
		shawpi.setScale(10,10);
		shawpi.setPosition(100,285);
		
	
	}
	
	

	
	void setThings()
	{
		setBoundaries();
		setPlatformsLeft();
		setLadders();
		setCharacters();
		
		
		
	}
	
}







#endif