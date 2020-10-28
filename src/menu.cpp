#include <iostream>
using namespace std ; 
#include "menu.h"
#include "fileoperations.h"
#include "classbookoperations.h"


void print_menu(){
	//system("clear");     //https://www.cplusplus.com/articles/4z18T05o/
	cout << endl << endl;
	cout << "Phone Book Application" << endl;
	cout << "Choose an operation" << endl;
	cout << "S: Record Search" << endl;
	cout << "A: Record Add" << endl;
	cout << "U: Record Update" << endl;
	cout << "D: Record Delete" << endl;	
	cout << "E: Exit" << endl;	
	cout << endl;
	cout << "Enter a choice {S,A,U,D,E}: ";
}
bool perform_operation(char choice, ClassBookFile classfile){
	bool terminate = false ; 
	switch(choice) {
		case 'S' : case 's' : 
			search_class(classfile); 
			break; 
		case 'A' : case 'a' : 
			add_class(classfile); 
			break; 
		case 'U' : case 'u' : 
			update_class(classfile); 
			break; 
		case 'D' : case 'd' : 
			delete_class(classfile) ; 
			break ; 
		case 'E' : case 'e' : 
			cout<<"are you sure you want to exit the program?(Y/N)"<<endl; 
			cin>>choice ; 
			if(choice == 'Y' || choice == 'y')
			{
				terminate = true ; 
			}
			break; 
		default : 
		cout<<"You have entered an invalid choice"<<endl; 
		cout<<"PLease try again <S, A, U, D, E>"<<endl; 
		cin>>choice; 
		terminate = perform_operation(choice, classfile); 
		break; 	
	
	
	}
	return terminate ; 
}
