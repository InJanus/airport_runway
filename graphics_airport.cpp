
#include <iostream>

#include "plane.cpp"

using namespace std;
//these will just be abunch of functions to help draw the airport using the plane class
class graphics_airport{
    public:
        graphics_airport(){
            airport_name = "My Airport";
            empty();
        }
        graphics_airport(string name, vector<plane> waitlist){
            graphics_airport();
            airport_name = name;
            this->waitlist = waitlist; 
            empty();
        }
        
        friend ostream& operator<<(ostream &output, graphics_airport &a){
            output << a.master;
            return output;
        }
        
        void empty(){
            
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
            master += " -------------------------------------------------------------------------------------| " + airport_name + "\n";
            master += "|  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _          __________  | Plane Wait List\n";
            if(waitlist.size() >= 1){master += "| +                                                             +        |          | | " + waitlist.at(0).getPlane_Menu(1) + "\n";}
            else{master += "| +                                                             +        |          | |\n";}
            if(waitlist.size() >= 2){master += "| + 3                                                           +        |   Fire   | | " + waitlist.at(1).getPlane_Menu(2) + "\n";}
            else{master += "| + 3                                                           +        |   Fire   | |\n";}
            if(waitlist.size() >= 3){master += "| +_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _+        |   Dpt.   | | " + waitlist.at(2).getPlane_Menu(3) + "\n";}
            else{master += "| +_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _+        |   Dpt.   | |\n";}
            if(waitlist.size() >= 4){master += "|                                                                        |          | | " + waitlist.at(3).getPlane_Menu(4) + "\n";}
            else{master += "|                                                                        |          | |\n";}
            if(waitlist.size() >= 5){master += "|   +++++    +++++                                                       |    #     | | " + waitlist.at(4).getPlane_Menu(5) + "\n";}
            else{master += "|   +++++    +++++                                                       |    #     | |\n";}
            if(waitlist.size() >= 6){master += "|  |     |  |     |                                                      =   ###    | | " + waitlist.at(5).getPlane_Menu(6) + "\n";}
            else{master += "|  |     |  |     |                                                      =   ###    | |\n";}
            if(waitlist.size() >= 7){master += "|  |     |  |     |                                                      =    #     | | " + waitlist.at(6).getPlane_Menu(7) + "\n";}
            else{master += "|  |     |  |     |                                                      =    #     | |\n";}
            if(waitlist.size() >= 8){master += "|  |     |  |     |                                                      =__________| | " + waitlist.at(7).getPlane_Menu(8) + "\n";}
            else{master += "|  |     |  |     |                                                      =__________| |\n";}
            if(waitlist.size() >= 9){master += "|  |     |  |     |                                                                   | Other planes waiting: " + to_string(waitlist.size() - 8) + "\n";}
            else{master += "|  |     |  |     |                                                                   |\n";}
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
        }
        
        void addPlane(plane input){
            waitlist.resize(waitlist.size()+1);
            waitlist.at(waitlist.size()-1) = input;
        }
        
        void removePlane(int pos){
            waitlist.erase(waitlist.begin() + (pos-1));
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
            
        }
    private:
        
        string master;
        string airport_name;
        vector<plane> waitlist;
};




int main(){
    vector<plane> inputp(20);
    for(int i = 0; i < inputp.size(); i++){
        inputp.at(i) = plane(i+1);    
    }
    
    graphics_airport test("CVG Airport",inputp);
    test.repaint();
    
    
    //test.removePlane(1);
    
    test.addPlane(plane(100));
    //cout << "-------------------------------------" << endl;
    //for(int i = 0; i < test.getWaitlist().size(); i++){
        //cout << test.getWaitlist().at(i) << endl;
    //}
    //cout << test.getWaitlist().at(0) << endl;
    
    
    //test.addplane(plane(10));
    
    
    //test.repaint();
    
    int input = 1;
    while(input!=0){
        cout << test;
        //test.repaint();
        test.start_screen_on();
        //test.addplane(plane(10));
        cin.get();
    } 

    
    return 0;
}

