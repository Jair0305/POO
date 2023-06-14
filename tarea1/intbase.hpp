#ifndef INTBASE_HPP
#define INTBASE_HPP

struct IntBase
{
	unsigned int num;

	void dec( char* string );
	void bin( char* string );
	void oct( char* string );
	void hex( char* string );
};
#endif
