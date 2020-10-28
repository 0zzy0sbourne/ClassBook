
#include "class_record.h"
struct ClassBookFile{
	const char* filename ; 
	FILE* classbook ; 
	void create(); 
	void close() ; 
    void remove( int ) ; 
	void add(Class_record*) ; 
	void update(int, Class_record*); 
	int search(char []) ; // returns the found numbers' amount 





}; 
