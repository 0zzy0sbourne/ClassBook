#include <iostream> 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <strings.h> 

using namespace std; 

#include "fileoperations.h"


void ClassBookFile::create()
{
    filename = "classbook.dat";
    classbook = fopen(filename, "r+"); 
    if(!classbook)
    {
        if(!(classbook  = fopen(filename, "w+")))
        {
            cerr<<"Can not open file"<<endl;
            exit(1);  
        }
        
    }
    
}
void ClassBookFile::close()
{
    fclose(classbook); 
}
void ClassBookFile::add(Class_record* ptr)
{
    fseek(classbook, 0, SEEK_END); 
    fwrite(ptr, sizeof(Class_record), 1, classbook); 
}
int  ClassBookFile::search(char* desired)
{
    Class_record  temp ; 
    int found = 0;
    int index = 0 ;  
    bool all = false; 
    if(strcmp(desired,"*") == 0)
        all = true ; 
    fseek(classbook, 0, SEEK_SET); 
    while(!feof(classbook))
    {
        index++ ; 
        fread(&temp, sizeof(Class_record), 1, classbook);  
        if(feof(classbook))
            break; 
        if(all || strncasecmp(temp.name, desired, strlen(desired))== 0)
        {
           cout<<index<<"-"<<temp.code<<" "<<temp.name<<endl; 
           found++;  
        }
    }
    return found ; 

}
void ClassBookFile::update(int recordnum,Class_record* ptr)
{
    if(fseek(classbook, sizeof(Class_record)*(recordnum-1), SEEK_SET) == 0) // upon successful process fseek returns 0 
    {
        fwrite(ptr, sizeof(Class_record), 1, classbook); 
    }
}
void ClassBookFile::remove(int recordnum)
{
    Class_record temp ; 
    int totalrecord = 0; 
    fseek(classbook, 0, SEEK_SET); 
    while(!feof(classbook))
    {
        fread(&temp, sizeof(Class_record), 1, classbook ); 
        totalrecord++; 
    }
    


}