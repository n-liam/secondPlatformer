

#ifndef ENTITY_H
#define ENTITY_H

	class Entity: public sf::Sprite
	{
		public:
			bool didCollideWith(Entity entity2)
			{
				sf::FloatRect box_sprite = (*this).getGlobalBounds();
				sf::FloatRect box_sprite2 = entity2.getGlobalBounds();
				if (box_sprite.intersects(box_sprite2) )
				{
					return true;
				}
				else 
				{

					return false;
				}
			}
		
		
		
		
	};


#endif