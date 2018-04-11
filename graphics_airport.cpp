
#include <iostream>

#include "location.cpp"

using namespace std;
//these will just be abunch of functions to help draw the airport using the plane class

class graphics_airport{
    public:
        graphics_airport(){
            airport_name = "My Airport";
            //empty();
        }
        graphics_airport(string name, vector<plane> waitlist,vector<bool> runwaylist, vector<bool> terminallist,vector<bool> terminalfuel){
            airport_name = name;
            this->waitlist = waitlist; 
            this->runwaylist = runwaylist;
            this->terminallist = terminallist;
            this->terminalfuel = terminalfuel;
            //myairport = airport(3,12);
            status1 = "";
            status2 = "";
            status3 = "";
            status4 = "";
            
        }

        void setName(string airport_name){
            this->airport_name = airport_name;
        }
        
        friend ostream& operator<<(ostream &output, graphics_airport &a){
            output << a.master;
            return output;
        }
        
        void empty(){
            //this is changed so much that do not use this template..
            master = string(50,'\n');
            master += " -------------------------------------------------------------------------------------| " + airport_name + "\n";
            master += "|  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _          __________  | Plane Wait List\n";
            master += "| +                                                             +        |          | |\n";
            master += "| + 3                                                           +        |   Fire   | |\n";
            master += "| +_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _+        |   Dpt.   | |\n";
            master += "|                                                                        |          | |\n";
            master += "|   +++++    +++++                                                       |    #     | |\n";
            master += "|  |     |  |     |                                                      =   ###    | |\n";
            master += "|  |     |  |     |                                                      =    #     | |\n";
            master += "|  |     |  |     |                                                      =__________| |\n";
            master += "|  |     |  |     |                                                                   |\n";
            master += "|  |     |  |     |                                                                   |\n";
            master += "|  |     |  |     |                                                                   |\n";
            master += "|  |     |  |     |                 \\8\\     \\9\\     \\1\\     \\1\\      \\1\\     \\1\\      |\n";
            master += "|  |     |  |     |                  \\ \\     \\ \\     \\0\\     \\1\\      \\2\\     \\3\\     |\n";
            master += "|  |     |  |     |                ###################################################|\n";
            master += "|  |     |  |     |               #                                                   |\n";
            master += "|  |     |  |     |               #                                                   |\n";
            master += "|  |     |  |     |               #                                                   |\n";
            master += "|  |     |  |     |                ###################################################|\n";
            master += "|  |  1  |  |  2  |                  / /     / /     / /     / /     / /      / /     |\n";
            master += "|  |     |  |     |                 /6/     /5/     /4/     /3/     /2/      /1/      |\n";
            master += "|   +++++    +++++                                                                    |\n";
            master += "|                                                                                     |\n";
            master += " -------------------------------------------------------------------------------------|\n";
            //Try using the += operator instead of x = x + ...
        }
        
        
        void repaint(){
            master = string(50,'\n');
            master += " ---------------------------------------------------------------------------------------------| " + airport_name + "\n";
            master += "|                                                                                             | Plane Wait List\n";
            master += "|  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _          __________  | # |  Name  | FuL | Cargo Type \n";
            if(waitlist.size() >= 1){if(runwaylist.at(2) == true){master += "| +            _|_    ";}else{master += "| +                   ";}master += "                                                  +        |          | | " + waitlist.at(0).getPlane_Menu(1) + "\n";}
            else{if(runwaylist.at(2) == true){master += "| +            _|_       ";}else{master += "| +                      ";}master += "                                               +        |          | |\n";}
            if(runwayop.at(2) == true){master += "| + 3 ";}else{master += "| + X ";}
            if(waitlist.size() >= 2){if(runwaylist.at(2) == true){master += "      *--oOo--* ";}else{master += "                ";}master += "                                                  +        |   Fire   | | " + waitlist.at(1).getPlane_Menu(2) + "\n";}
            else{if(runwaylist.at(2) == true){master += "      *--oOo--*    ";}else{master += "                   ";}master += "                                               +        |   Fire   | |\n";}
            if(waitlist.size() >= 3){master += "| +_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _+        |   Dpt.   | | " + waitlist.at(2).getPlane_Menu(3) + "\n";}
            else{master += "| +_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _+        |   Dpt.   | |\n";}
            if(waitlist.size() >= 4){master += "|                                                                                |          | | " + waitlist.at(3).getPlane_Menu(4) + "\n";}
            else{master += "|                                                                                |          | |\n";}
            if(waitlist.size() >= 5){master += "|   + + + + +    + + + + +                                                       |    #     | | " + waitlist.at(4).getPlane_Menu(5) + "\n";}
            else{master += "|   + + + + +    + + + + +                                                       |    #     | |\n";}
            if(waitlist.size() >= 6){master += "|  |         |  |         |                                                      =   ###    | | " + waitlist.at(5).getPlane_Menu(6) + "\n";}
            else{master += "|  |         |  |         |                                                      =   ###    | |\n";}
            if(waitlist.size() >= 7){master += "|  |         |  |         |                                                      =    #     | | " + waitlist.at(6).getPlane_Menu(7) + "\n";}
            else{master += "|  |         |  |         |                                                      =    #     | |\n";}
            if(waitlist.size() >= 8){master += "|  |         |  |         |                                                      =__________| | " + waitlist.at(7).getPlane_Menu(8) + "\n";}
            else{master += "|  |         |  |         |                                                      =__________| |\n";}
            if(waitlist.size() >= 9){master += "|  |         |  |         |                                                                   | Other planes waiting: " + to_string(waitlist.size() - 8) + "\n";}
            else{master += "|  |         |  |         |                                                                   |\n";}
            master += "|  |         |  |         |                                                                   | Commands\n";
            master += "|  |         |  |         |          ";
            if(terminallist.at(6) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(7) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(8) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(9) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(10) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(11) == true){master += "   _|_   ";}else{master += "         ";}
            master += "   | land [waitlist] [runway] [terminal]\n";
            master += "|  |         |  |         |          ";
            if(terminallist.at(6) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(7) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(8) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(9) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(10) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(11) == true){master += "*--oOo--*";}else{master += "         ";}
            master += "   | takeoff [terminal] [runway]\n";
            master += "|  |         |  |         |             ";
            if(terminalop.at(6) == true){master += "\\7\\      ";}else{master += "\\X\\      ";}
            if(terminalop.at(7) == true){master += "\\8\\      ";}else{master += "\\X\\      ";}
            if(terminalop.at(8) == true){master += "\\9\\      ";}else{master += "\\X\\      ";}
            if(terminalop.at(9) == true){master += "\\1\\      ";}else{master += "\\X\\      ";}
            if(terminalop.at(10) == true){master += "\\1\\      ";}else{master += "\\X\\      ";}
            if(terminalop.at(11) == true){master += "\\1\\      ";}else{master += "\\X\\      ";}
            master += "| clean [terminal/runway]\n";
            master += "|  |         |  |         |              \\ \\      \\ \\      \\ \\      ";
            if(terminalop.at(9) == true){master += "\\0\\      ";}else{master += "\\ \\      ";}
            if(terminalop.at(10) == true){master += "\\1\\      ";}else{master += "\\ \\      ";}
            if(terminalop.at(11) == true){master += "\\2\\     ";}else{master += "\\ \\     ";}
            master += "| \n";
            master += "|  |         |  |         |             ######################################################| \n";
            if(runwaylist.at(0) == true){master += "|  |   _|_   |  |";}else{master += "|  |         |  |";}
            if(runwaylist.at(1) == true){master += "   _|_   |            #   ";}else{master += "         |            #   ";}
            if(terminalfuel.at(6) == true){master += "D        ";}else{master += "         ";}
            if(terminalfuel.at(7) == true){master += "D        ";}else{master += "         ";}
            if(terminalfuel.at(8) == true){master += "D        ";}else{master += "         ";}
            if(terminalfuel.at(9) == true){master += "D        ";}else{master += "         ";}
            if(terminalfuel.at(10) == true){master += "D        ";}else{master += "         ";}
            if(terminalfuel.at(11) == true){master += "D     ";}else{master += "      ";}  
            master += "| " + status1 + "\n";
            if(runwaylist.at(0) == true){master += "|  |*--oOo--*|  |";}else{master += "|  |         |  |";}
            if(runwaylist.at(1) == true){master += "*--oOo--*|            #                                                      | " + status2 + "\n";}else{master += "         |            #                                                      | " + status2 + "\n";}
            master += "|  |         |  |         |            #   ";
            if(terminalfuel.at(5) == true){master += "D        ";}else{master += "         ";}
            if(terminalfuel.at(4) == true){master += "D        ";}else{master += "         ";}
            if(terminalfuel.at(3) == true){master += "D        ";}else{master += "         ";}
            if(terminalfuel.at(2) == true){master += "D        ";}else{master += "         ";}
            if(terminalfuel.at(1) == true){master += "D        ";}else{master += "         ";}
            if(terminalfuel.at(0) == true){master += "D     ";}else{master += "      ";}
            master += "| " + status3 + "\n";
            master += "|  |         |  |         |             ######################################################| " + status4 + "\n"; 
            if(runwayop.at(0) == true){master += "|  |    1";}else{master += "|  |    X";}
            if(runwayop.at(1) == true){master += "    |  |    2";}else{master += "    |  |    X";}      
            master += "    |              / /      / /      / /      / /      / /      / /     | " + status5 + "\n";          
            master += "|  |         |  |         |             ";
            if(terminalop.at(5) == true){master += "/6/      ";}else{master += "/X/      ";}
            if(terminalop.at(4) == true){master += "/5/      ";}else{master += "/X/      ";}
            if(terminalop.at(3) == true){master += "/4/      ";}else{master += "/X/      ";}
            if(terminalop.at(2) == true){master += "/3/      ";}else{master += "/X/      ";}
            if(terminalop.at(1) == true){master += "/2/      ";}else{master += "/X/      ";}
            if(terminalop.at(0) == true){master += "/1/      | \n";}else{master += "/X/      | \n";}
            master += "|   + + + + +    + + + + +           ";
            if(terminallist.at(5) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(4) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(3) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(2) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(1) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(0) == true){master += "   _|_   ";}else{master += "         ";}
            master += "   | 1) Type your command into command_here.txt\n";          
            master += "|                                    ";
            if(terminallist.at(5) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(4) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(3) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(2) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(1) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(0) == true){master += "*--oOo--*";}else{master += "         ";}
            master += "   | 2) Save command_here.txt\n";          
            master += " ------------------------------Game Ends when you Crash 20 planes-----------------------------| 3) The command gets sent to the program!\n";
            
            
            //plane ideas...
            
            //       __|__
            //--@--@--(_)--@--@--   size 3
            
            //      _|_
            //----oo(_)oo----   size 2
            
            //   _|_    
            //*--oOo--*   size 1        foucusing on size one for trhe moment. 
            
        }
    

        void endscreen_crash(){
            master = string(50,'\n');
            master += "                                                  Congratulations! You crashed 20 planes!                                \n";
            master += "                                               You have lost your job as air-traffic control                              \n";
            master += "\n";
            master += "                                                                    |                                                    \n";
            master += "                                                                    |                                                    \n";
            master += "                                                                  .-'-.                                                  \n";
            master += "                                                                 ' ___ '                                                 \n";
            master += "                                                       ---------'  .-.  '---------                                       \n";
            master += "                                       _________________________'  '-'  '_________________________                       \n";
            master += "                                        ''''''-|---|--/    \\==][^',_m_,'^][==/    \\--|---|-''''''                        \n";
            master += "                                                      \\    /  ||/   H   \\||  \\    /                                      \n";
            master += "                                                       '--'   OO   O|O   OO   '--'                                       \n";
            master += "\n";
            master += "                                                           Press ENTER to exit                                           \n";
            master += string(8, '\n');
        }
        
        vector<plane> getWaitlist(){
            return waitlist;
        }
        
        void start_screen_on(){
            master = string(50,'\n');
            master += "                             _____________________________________________________________________________________\n";
            master += "                             #                _______                      _                _                    #\n";
            master += "                             #               |__   __|                    (_)              | |                   #\n";
            master += "                             #                  | |  ___  _ __  _ __ ___   _  _ __    __ _ | |                   #\n";
            master += "                             #                  | | / _ \\| '__|| '_ ` _ \\ | || '_ \\  / _` || |                   #\n";
            master += "                             #                  | ||  __/| |   | | | | | || || | | || (_| || |                   #\n";
            master += "                             #                  |_| \\___||_|   |_| |_| |_||_||_| |_| \\__,_||_|                   #\n";
            master += "                             #                                                                                   #\n";
            master += "                             #                            Enter your airport name                                #\n";
            master += "                             #                         in command_here.txt and save                              #\n";
            master += "                             _____________________________________________________________________________________\n";
            master += string(8,'\n');
            
        }
        
        void start_screen_off(){
            master = string(50,'\n');
            //master += " -------------------------------------------------------------------------------------|";
            master += "                             *************************************************************************************\n";
            master += "                             |                _______                      _                _                    |\n";
            master += "                             |               |__   __|                    (_)              | |                   |\n";
            master += "                             |                  | |  ___  _ __  _ __ ___   _  _ __    __ _ | |                   |\n";
            master += "                             |                  | | / _ \\| '__|| '_ ` _ \\ | || '_ \\  / _` || |                   |\n";
            master += "                             |                  | ||  __/| |   | | | | | || || | | || (_| || |                   |\n";
            master += "                             |                  |_| \\___||_|   |_| |_| |_||_||_| |_| \\__,_||_|                   |\n";
            master += "                             |                                                                                   |\n";
            master += "                             |                            Enter your airport name                                |\n";
            master += "                             |                         in command_here.txt and save                              |\n";
            master += "                             *************************************************************************************\n";
            master += string(8, '\n');
            
        }
        
        void setWaitList(vector<plane> waitlist){
            this->waitlist = waitlist;
        }
        
        void setData(vector<plane> waitlist, vector<bool> runwaylist, vector<bool> terminallist, string status1,string status2,string status3, string status4, string status5, vector<bool> terminalfuel, vector<bool> runwayop, vector<bool> terminalop){
            this->waitlist = waitlist; 
            this->runwaylist = runwaylist;
            this->terminallist = terminallist;
            this->terminalfuel = terminalfuel;
            this->status1 = status1;
            this->status2 = status2;
            this->status3 = status3;
            this->status4 = status4;
            this->status5 = status5;
            this->runwayop = runwayop;
            this->terminalop = terminalop;
        }
        
        
        
        
        
        
    private:
        
        string master;
        string airport_name;
        string status1;
        string status2;
        string status3;
        string status4;
        string status5;
        //airport myairport;
        vector<plane> waitlist;
        vector<bool> runwaylist;
        vector<bool> terminallist;
        vector<bool> terminalfuel;
        vector<bool> runwayop;
        vector<bool> terminalop;
};




/*
int main(){
    //thread t1(test_thread);
    //t1.join();
    
    vector<plane> inputp(3);
    for(int i = 0; i < inputp.size(); i++){
        inputp.at(i) = plane(i+1);    
    }
    vector<bool> runway(3);
    for(int i = 0; i < 3; i++){
        runway.at(i) = false;
    }
    vector<bool> terminal(12);
    for(int i = 0; i < 12; i++){
        terminal.at(i) = false;
    }

    vector<bool> fuel(12);
    for(int i = 0; i < 12; i++){
        fuel.at(i) = false;
    }
    
    graphics_airport test("CVG Airport",inputp,runway,terminal,fuel);
    test.repaint();
    
    
    //test.removePlane(1);
    
    //test.addPlane(plane(100));
    //cout << "-------------------------------------" << endl;
    //for(int i = 0; i < test.getWaitlist().size(); i++){
        //cout << test.getWaitlist().at(i) << endl;
    //}
    //cout << test.getWaitlist().at(0) << endl;
    
    
    //test.addplane(plane(10));
    
    
    //test.repaint();
    cout << test;
    cin.get();
    //int input = 1;
    
    while(input!=0){
        cout << test;
        
        //test.repaint();
        test.start_screen_on();
        //test.addplane(plane(10));
        pause(1);
        cout << test;
        test.start_screen_off();
        pause(1);
    } 
    

    
    return 0;
}
*/


