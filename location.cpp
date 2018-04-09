#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <string>
#include "plane.cpp"

using namespace std;

class location{
    public: 
        
        //things to do before you go how each one works
        
        //default constructor
        //set constructor
        
        //fuctions
            //void addPlane
            //void removePlane
            //bool locationInOrder
            
        //private data
            //terminal number
            
        //sets and gets
            
            
        //foucus on this and then ask me for questions if need be.
        //as soon as we get this done, i can be finished in a few days. then we can be done early
            
        
        
        location(int terminal_name){
            //this->terminal_name = terminal_name;
            myplane = plane();
            myplane.setPlane_Name("");
            isfuct = true;
        }
        
        location(){
            //terminal_name = 0;
            myplane = plane();
            myplane.setPlane_Name("");
            isfuct = true;
        }
        
        void addPlane(plane input){
            if(isfuct){
                if(myplane.getPlane_Name() == ""){
                    //add the plane
                    myplane = input;
                    
                }else{
                    isfuct = false;
                    //location is not fuct
                }
            }
        }
        
        void removePlane(){
            myplane.setPlane_Name("");
        }
        
        bool isFuctional(){
            return isfuct;
        }
        
        void makeFuct(){
            myplane.setPlane_Name("");
            isfuct = true;
        }
        
        bool isOcc(){
            return(myplane.getPlane_Name() != "");
        }
        
        plane getPlane(){
            return myplane;
        }
        
        
        
        
    
    private:    //declare your private data first
        //int terminalSize;
        //int terminal_name;    //just make it an int for the name// why is that?  //thats how i am refrencing them by // sounds good, just curious
        plane myplane;
        bool isfuct;
    
};
