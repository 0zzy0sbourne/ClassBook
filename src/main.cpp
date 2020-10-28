#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include <time.h> /* time */
#include <string.h> 
using namespace std; 
#include "fileoperations.h"
#include "menu.h"
int main()
{
	ClassBookFile classbook ; 
	classbook.create(); 
	bool end = false ; 
	char choice ; 
	while(!end)
	{
		print_menu();
		cin>>choice ; 
		end = perform_operations(choice,classbook);  
	}
	classbook.close(); 
	return EXIT_SUCCESS; 
	return 0 ; 
}











