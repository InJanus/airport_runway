#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

class terminal{
    public: 
        
        //things to do before you go how each one works
        
        //default constructor
        //set constructor
        
        //fuctions
            //void addPlane
            //void removePlane
            //bool terminalInOrder
            
        //private data
            //terminal number
            
            
        //foucus on this and then ask me for questions if need be.
        //as soon as we get this done, i can be finished in a few days. then we can be done early
            
        
        
        terminal(int terminal_size) {
            //int terminal_size = 1;  
        }
    
        bool airportFULL(bool open){
        bool fullcapacity;
            if(bool open == true){
            
                cout << "Plane can safely land" << endl;        //right idea but we dont want a cout statment just a true or false
            
            else {
                cout << "Plane will not land safely" << endl;
            }
        }
    }
    
    
    
    private:    //declare your private data first
        int terminalSize;
        int terminalName;    //just make it an int for the name// why is that?  //thats how i am refrencing them by // sounds good, just curious
        int terminalNumber;
        
    
    
};
