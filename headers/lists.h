#ifndef LISTS_H
#define LISTS_H

class List
{
	public:
		int m_index =0;
		
		int index() {return m_index;}
	
};


////////////////////////////////////////////////////
/// NOTE: these lists are lists of pointers toward objects, not lists of the objects themselves
///////////

class IntList: public List
{
	public:
		int *m_list [40];
	
		void add(int* address)
		{
			m_list[ m_index ] = address;
			m_index++;
			assert( m_index <= 40);
		}
	
	
};











#endif