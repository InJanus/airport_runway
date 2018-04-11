#include <iostream>
#include <thread>
//local functions
//#include "graphics_airport.cpp"
#include "airport.cpp"




using namespace std;

int main(){
    
    airport myairport = airport(3,12); //3 runways 12 terminals
    myairport.addRandomPlane();
    myairport.addRandomPlane();
    myairport.addRandomPlane(); //start with 4 random planes
    myairport.addRandomPlane();
    int counter = 0;
    int difficulty = 1;
    //graphics_airport g_air = graphics_airport("CVG Airport",myairport.getRunway(),myairport.getTerminal());
    
    vector<plane> inputp(0);
    vector<bool> runway(3);
    vector<bool> terminal(12);
    vector<bool> fuel(12);
    vector<bool> rop(3);
    vector<bool> top(12);
    string temp;
    vector<string> status(5);
    int thetime = 0;
    int crashed = 0;
    int startscreencount = 0;
    bool start = false;

    inputp = myairport.getWaitlist();
    runway = myairport.getRunway();
    terminal = myairport.getTerminal();
    fuel = myairport.getFuel();
    
    graphics_airport g_air("CVG Airport",inputp,runway,terminal, fuel);
    
    //myairport.landPlane(1,1);
    //myairport.landTerminal(1,1);
    //myairport.takeoff(1,2);
    //myairport.removeFromRunway(2);
    while(start == false){
        startscreencount++;
        if(startscreencount%2){
            g_air.start_screen_on();
        }else{
            g_air.start_screen_off();
        }
        
        temp = getFileCommand("command_here.txt");
        clearFile("command_here.txt");
        if(temp != ""){
            g_air.setName(temp);
            start = true;
        }
        cout << g_air;
        pause(1);
        cout << "_" << endl;
    }
    
    
    while(crashed < 20){
        if((int)(rand()%99+1) <= difficulty){ //1% chance start
            myairport.addRandomPlane();
        }
        if(counter >= 180){
            counter = 0;
            difficulty++;
        }
        temp = getFileCommand("command_here.txt");
        clearFile("command_here.txt");
        myairport.getCommand(temp);
        myairport.action();
        inputp = myairport.getWaitlist();
        runway = myairport.getRunway();
        terminal = myairport.getTerminal();
        fuel = myairport.getFuel();
        status = myairport.getStatus(difficulty);
        rop = myairport.getROP();
        top = myairport.getTOP();
        g_air.setData(inputp, runway, terminal, status.at(0), status.at(1), status.at(2), status.at(3),status.at(4), fuel, rop, top);
        g_air.repaint();
        cout << g_air;
        counter++;
        crashed = myairport.getCrashed();
        pause(1);
    }

    g_air.endscreen_crash();
    cout << g_air;
    cin.get();



    //this is where you output the achevements...
    //if i have time i can do it
    
    return 0; 
}

    //cout << repaint() << endl;
    
    //runner
        //plane - Brian     prototype done
        //size level
            //cargo
            //fuel level
        //runway
        //terminal
        //
        
    //money class/ user class   Brian
                            //resarch threads for multi function capabilities
    //graphics class / all text based   Brian
    
    
    //cout << "Hello World!" << endl;


//COLE!!!!!!!!!!!!!!!!

//for the terminal class...
    //i would make it so it can store one plane at a time and if two plances get added then the terminal is closed aka two planes collided
    //same for the runway class
    //after some amount of time. the terminal will reopen due to the fire fighters get it cleaned up leave that to me. just have a fuction that can change its open status
    
    // the goal is that i am going to make it a array that i can put in the graphics class
    
    //i am going to look up threads so we can run two things at once. i have done this once before.
    //i found somthing for threads and cloud 9 supports it so its a go!
    
    /////////////////////////////////////////////////////////
    
    //threads are unsucessful :(
    
    //there is still a way to get this to work
    //using a text file as the command propt kind of thing
    //put in commands to send it to the program
    //i will figure that out and make some functions for it
    
    
    // 

