
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
        graphics_airport(string name, vector<plane> waitlist,vector<bool> runwaylist, vector<bool> terminallist){
            airport_name = name;
            this->waitlist = waitlist; 
            empty();
            this->runwaylist = runwaylist;
            this->terminallist = terminallist;
            //myairport = airport(3,12);
            
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
            master += "|  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _          __________  | # |  Name  | FuL | S | Cargo Type \n";
            if(waitlist.size() >= 1){if(runwaylist.at(2) == true){master += "| +            _|_    ";}else{master += "| +                   ";}master += "                                                  +        |          | | " + waitlist.at(0).getPlane_Menu(1) + "\n";}
            else{if(runwaylist.at(2) == true){master += "| +            _|_       ";}else{master += "| +                      ";}master += "                                               +        |          | |\n";}
            if(waitlist.size() >= 2){if(runwaylist.at(2) == true){master += "| + 3       *--oOo--* ";}else{master += "| + 3                 ";}master += "                                                  +        |   Fire   | | " + waitlist.at(1).getPlane_Menu(2) + "\n";}
            else{if(runwaylist.at(2) == true){master += "| + 3       *--oOo--*    ";}else{master += "| + 3                    ";}master += "                                               +        |   Fire   | |\n";}
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
            master += "|  |         |  |         |                                                                   |\n";
            master += "|  |         |  |         |          ";
            if(terminallist.at(6) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(7) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(8) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(9) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(10) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(11) == true){master += "   _|_   ";}else{master += "         ";}
            master += "   | Commands\n";
            master += "|  |         |  |         |          ";
            if(terminallist.at(9) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(7) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(8) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(9) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(10) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(11) == true){master += "*--oOo--*";}else{master += "         ";}
            master += "   | land [waitlist] [runway]\n";
            master += "|  |         |  |         |             \\7\\      \\8\\      \\9\\      \\1\\      \\1\\      \\1\\      | terminal [runway] [terminal]\n";
            master += "|  |         |  |         |              \\ \\      \\ \\      \\ \\      \\0\\      \\1\\      \\2\\     | takeoff [terminal] [runway]\n";
            master += "|  |         |  |         |             ######################################################| ton [runway]\n";
            if(runwaylist.at(0) == true){master += "|  |   _|_   |  |";}else{master += "|  |         |  |";}
            if(runwaylist.at(1) == true){master += "   _|_   |            #                                                      | clean [terminal/runway]\n";}else{master += "         |            #                                                      | clean [terminal/runway]\n";}
            if(runwaylist.at(0) == true){master += "|  |*--oOo--*|  |";}else{master += "|  |         |  |";}
            if(runwaylist.at(1) == true){master += "*--oOo--*|            #                                                      | \n";}else{master += "         |            #                                                      | \n";}
            master += "|  |         |  |         |            #                                                      | \n";
            master += "|  |         |  |         |             ######################################################|    \n";          
            master += "|  |    1    |  |    2    |              / /      / /      / /      / /      / /      / /     | To send a command:\n";          
            master += "|  |         |  |         |             /6/      /5/      /4/      /3/      /2/      /1/      | 1) Type your command into command_here.txt\n";
            master += "|   + + + + +    + + + + +           ";
            if(terminallist.at(5) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(4) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(3) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(2) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(1) == true){master += "   _|_   ";}else{master += "         ";}
            if(terminallist.at(0) == true){master += "   _|_   ";}else{master += "         ";}
            master += "   | 2) When done typing your command, save\n";          
            master += "|                                    ";
            if(terminallist.at(5) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(4) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(3) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(2) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(1) == true){master += "*--oOo--*";}else{master += "         ";}
            if(terminallist.at(0) == true){master += "*--oOo--*";}else{master += "         ";}
            master += "   | command_here.txt\n";          
            master += " ---------------------------------------------------------------------------------------------| 3) The command gets sent to the program!\n";
            
            
            //plane ideas...
            
            //       __|__
            //--@--@--(_)--@--@--   size 3
            
            //      _|_
            //----oo(_)oo----   size 2
            
            //   _|_    
            //*--oOo--*   size 1        foucusing on size one for trhe moment. 
            
        }
    
        
        vector<plane> getWaitlist(){
            return waitlist;
        }
        
        void start_screen_on(){
            master = string(50,'\n');
            //master += " -------------------------------------------------------------------------------------|";
            master += "_____________________________________________________________________________________\n";
            master += "|                                                                                   |\n";
            master += "|       ████████ ███████ ██████╗ ███╗   ███ ██ ███╗   ██ ╗█████╗ ██╗                |\n";     
            master += "|       ╚══██╔══ ██╔════ ██╔══██ ████╗ ████ ██ ████╗  ██ ██╔══██ ██║                |\n";
            master += "|          ██║   █████╗  ██████╔ ██╔████╔██ ██ ██╔██╗ ██ ███████ ██║                |\n";
            master += "|          ██║   ██╔══╝  ██╔══██ ██║╚██╔╝██ ██ ██║╚██╗██ ██╔══██ ██║                |\n";
            master += "|          ██║   ███████ ██║  ██ ██║ ╚═╝ ██ ██ ██║ ╚████ ██║  ██ ███████╗           |\n";
            master += "|          ╚═╝   ╚══════ ╚═╝  ╚═ ╚═╝     ╚═ ╚═ ╚═╝  ╚═══ ╚═╝  ╚═ ╚══════╝           |\n";
            master += "|                                                                                   |\n";
            master += "|                                                                                   |\n";
            master += "|                            Press ENTER to play                                    |\n";
            master += "|                                                                                   |\n";
            master += "_____________________________________________________________________________________\n";
            
            
        }
        
        void start_screen_off(){
            master = string(50,'\n');
            //master += " -------------------------------------------------------------------------------------|";
            master += "_____________________________________________________________________________________\n";
            master += "|                                                                                   |\n";
            master += "|       ▒▒▒▒▒▒▒▒ ▒▒▒▒▒▒▒ ▒▒▒▒▒▒╗ ▒▒▒╗   ▒▒▒ ▒▒ ▒▒▒╗   ▒▒ ╗▒▒▒▒▒╗ ▒▒╗                |\n";     
            master += "|       ╚══▒▒╔══ ▒▒╔════ ▒▒╔══▒▒ ▒▒▒▒╗ ▒▒▒▒ ▒▒ ▒▒▒▒╗  ▒▒ ▒▒╔══▒▒ ▒▒║                |\n";
            master += "|          ▒▒║   ▒▒▒▒▒╗  ▒▒▒▒▒▒╔ ▒▒╔▒▒▒▒╔▒▒ ▒▒ ▒▒╔▒▒╗ ▒▒ ▒▒▒▒▒▒▒ ▒▒║                |\n";
            master += "|          ▒▒║   ▒▒╔══╝  ▒▒╔══▒▒ ▒▒║╚▒▒╔╝▒▒ ▒▒ ▒▒║╚▒▒╗▒▒ ▒▒╔══▒▒ ▒▒║                |\n";
            master += "|          ▒▒║   ▒▒▒▒▒▒▒ ▒▒║  ▒▒ ▒▒║ ╚═╝ ▒▒ ▒▒ ▒▒║ ╚▒▒▒▒ ▒▒║  ▒▒ ▒▒▒▒▒▒▒╗           |\n";
            master += "|          ╚═╝   ╚══════ ╚═╝  ╚═ ╚═╝     ╚═ ╚═ ╚═╝  ╚═══ ╚═╝  ╚═ ╚══════╝           |\n";
            master += "|                                                                                   |\n";
            master += "|                                                                                   |\n";
            master += "|                            Press ENTER to play                                    |\n";
            master += "|                                                                                   |\n";
            master += "_____________________________________________________________________________________\n";
            
        }
        
        void setWaitList(vector<plane> waitlist){
            this->waitlist = waitlist;
        }
        
        void setData(vector<plane> waitlist, vector<bool> runwaylist, vector<bool> terminallist){
            this->waitlist = waitlist; 
            this->runwaylist = runwaylist;
            this->terminallist = terminallist;
        }
        
        
        
        
        
        
    private:
        
        string master;
        string airport_name;
        //airport myairport;
        vector<plane> waitlist;
        vector<bool> runwaylist;
        vector<bool> terminallist;
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
    
    graphics_airport test("CVG Airport",inputp,runway,terminal);
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
    /*
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
    */

    
    //return 0;
//}


