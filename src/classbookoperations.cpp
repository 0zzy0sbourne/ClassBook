#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

#include "menu.h"
#include "fileoperations.h"





void  add_class(ClassBookFile classfile)
{
	Class_record newclass; 
	cout<<"PLease enter class information you want to add"<<endl; 
       	cout<<"Name:"; 
	cin.ignore(1000, '\n'); 
	cin.getline(newclass.name, NAME_LENGTH);
	cout<<"Code:"<<endl;
	cin>>setw(CODE_LENGTH)>>newclass.code; 

	classfile.add(&newclass); 
	cout<<"Record added"<<endl;
	getchar(); 
}

void search_record(ClassBookFile classfile){
	char name[NAME_LENGTH]; 
	cout<<"Please Enter the name of the Class you want to search for (press * to see full list" <<endl; 
	cin.ignore(1000, '\n'); 
	cin.getline(name, NAME_LENGTH); 
	if(classfile.search(name) == 0)
	{
		cout<<"No matching result for your input"<<endl; 
	}
	getchar(); 

}

void update_record(ClassBookFile classfile)
{	
	int num; 
	int class_count ; 
	char choice ; 
	char name[NAME_LENGTH]; 
	char code[CODE_LENGTH]; 
	cout<<"Do you want to search by code or name of the class? (type c/n)"<<endl; 
	cin>>choice; 
	switch(choice) {
		case 'c' : case 'C':
		    cout<<"Enter the code of the class:(press * for the full list"<<endl; 
			cin.getline(code,CODE_LENGTH); 
			class_count = 	classfile.search(code);
			break;
		case 'N' : case 'n' :
			cout<<"Enter the name of the class:( press * for the fulllist"<<endl; 
			cin.getline(name,NAME_LENGTH); 
			class_count = classfile.search(name); 
			break; 
	
	}
	if(class_count == 0) 
	{
		cout<<"Could not find a record matching"<<endl; 
	}

	else{
		if(class_count == 1)
		{
			cout<<"Class found"<<endl; 
			cout<<"Enter 0 if you want to update this class(Enter -1to exit without performing any operations):"<<endl;
		}
		else{
			cout<<"ENter the number of the class record you want to update(Enter -1 to exit without performing any operations.):"<<endl; 
		}
	
	
	cin>>num; 
	if(num == -1) return; 
	Class_record newclass ; 
	cout<<"Enter the class information that you want to replace with:"<<endl; 
	cout<<"Name:";
	cin.ignore(1000,'\n'); 
	cin.getline(newclass.name, NAME_LENGTH); 
	cout<<"Code:";
	cin>>setw(CODE_LENGTH)>>newclass.code; 
	classfile.update(num,&newclass);
       	cout<<"Record Successfully Updated!"<<endl;
	}
	getchar(); 	
}