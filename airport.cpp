
#include <vector>
#include <sstream>

#include "command.cpp"
#include "graphics_airport.cpp"


//using namespace std;



class airport{
    public:
        airport(){
            r.resize(0);
            t.resize(0);
            w.resize(0);
            planes_crashed = 0;
        }
        
        airport(int r_size, int t_size){
            r.resize(r_size);
            r_time.resize(r_size);
            t.resize(t_size);
            t_time.resize(r_size);
            w.resize(0);
            planes_crashed = 0;
            r_time_ts.resize(r_size);
            t_time_ts.resize(r_size);
            t_clean.resize(t_size);
            r_clean.resize(r_size);
            fireDispached = false;
            fireKilled = false;
        }
        
        
        
        void landPlane(int wait, int run, int term){
            
            plane temp = w.at(wait-1);
            removePlane(wait);
            r.at(run-1).addPlane(temp);
            r_time.at(run-1) = 15;
            t_time.at(run-1) = term-1; //this needs to be term-1

            if(!r.at(run-1).isFuctional()){
                if(r_clean.at(run-1) > 0){
                    fireKilled = true;
                }
                r.at(run-1).removePlane();
                planes_crashed++;
            }else{
                if(rand()%49 == 0){
                    r.at(run-1).removePlane();
                    r.at(run-1).makeNotFuct();
                    planes_crashed++;
                }
            }


        }
        /*
        void clean(int num){
            if(r.at())
        }
        */

        vector<string> getStatus(int difficulty){
            vector<string> temp(5);

            temp.at(0) = "Runways down: ";
            for(int i = 0; i < 3; i++){
                if(!r.at(i).isFuctional()){
                    temp.at(0) += to_string(i+1);
                    temp.at(0) += " ";
                }
            }
            temp.at(1) = "Terminals Down: ";
            for(int i = 0; i < 12; i++){
                if(!t.at(i).isFuctional()){
                    temp.at(1) += to_string(i+1);
                    temp.at(1) += " ";
                }
            }
            temp.at(2) = "Planes Crashed: " + to_string(planes_crashed);
            if(fireKilled){
                temp.at(3) = "FIRE DEPARTMENT HAS BEEN KILLED";
            }else if(fireDispached){
                temp.at(3) = "FIRE DEPARTMENT HAS BEEN DISPATCHED";
            }else{
                temp.at(3) = "";
            }
            temp.at(4) = "Level: " + to_string(difficulty);

            return temp;
            
        }

        vector<bool> getROP(){
            vector<bool> temp(3);
            for(int i = 0; i < 3; i++){
                temp.at(i) = r.at(i).isFuctional();
            }
            return temp;
        }
        vector<bool> getTOP(){
            vector<bool> temp(12);
            for(int i = 0; i < 12; i++){
                temp.at(i) = t.at(i).isFuctional();
            }
            return temp;
        }
        
        void landTerminal(int run, int term){
            plane temp = r.at(run-1).getPlane();
            r.at(run-1).removePlane();
            t.at(term).addPlane(temp);

            if(!t.at(term).isFuctional()){
                if(t_clean.at(term) > 0){
                    fireKilled = true;
                }
                t.at(term).removePlane();
                planes_crashed++;
            }else{
                if(rand()%49 == 0){
                    t.at(term).removePlane();
                    t.at(term).makeNotFuct();
                    planes_crashed++;
                }
            }
        }
        
        void takeoff(int term, int run){
            plane temp = t.at(term-1).getPlane();
            t.at(term-1).removePlane();
            r.at(run-1).addPlane(temp);

            r_time_ts.at(run-1) = 15;
            t_time_ts.at(run-1) = run-1;          

            if(!r.at(run-1).isFuctional()){
                if(r_clean.at(run-1) > 0){
                    fireKilled = true;
                }
                r.at(run-1).removePlane();
                planes_crashed++;
            }else{
                if(r.at(run-1).getPlane().getFuel_Level() < 900){
                    if(rand()%2 == 0){
                        r.at(run-1).removePlane();
                        r.at(run-1).makeNotFuct();
                        planes_crashed++;
                    }
                }
            }
            
        }
        
        void removeFromRunway(int run){
            r.at(run-1).removePlane();
        }
        
        void getCommand(string command){
            string scom = "";
            int num1 = 0;
            int num2 = 0;
            int num3 = 0;
            
            istringstream input(command);
            
            input >> scom; 
            input >> num1;//this gets all of the commands and splits them up 
            input >> num2;
            input >> num3;

            if((num1>12)&&(num1<1)){
                scom = "";
            }
            if((num2>12)&&(num2<1)){
                scom = "";
            }
            if((num3>12)&&(num3<1)){
                scom = "";
            }
            
            if(scom == "land"){
                if((num1>=1)&&(num1<=w.size())){
                    if((num2<=3)&&(num2>=1)){
                        if((num3<=12)&&(num3>=1)){
                            landPlane(num1,num2, num3);
                        }
                    }
                }
            }else if(scom == "takeoff"){
                if((num1<=12)&&(num1>=1)){
                    if((num2<=3)&&(num2>=1)){
                        takeoff(num1,num2);
                    }
                }
            }else if(scom == "clean"){
                if((num1<=12)&&(num1>=1)){
                    clean(num1);
                }
            }
            
        }

        void clean(int num){
            if(!fireKilled){
                if(num<4){
                    if(!r.at(num-1).isFuctional()){
                        r_clean.at(num-1) = 60; //60 seconds
                        fireDispached = true;
                    }
                }
                if(!fireDispached){
                    if(!t.at(num-1).isFuctional()){
                        t_clean.at(num-1) = 60;
                        fireDispached = true;
                    }
                }
            }
        }

        void now_clean(int num){
            if(!fireKilled){
                if(num < 4){
                    if(!r.at(num-1).isFuctional()){
                        r.at(num-1).makeFuct();
                        fireDispached = false;
                    }
                }
                if(fireDispached){
                    if(!t.at(num-1).isFuctional()){
                        t.at(num-1).makeFuct();
                        fireDispached = false;
                    }
                }
            }
        }
        
        void refuel(){
            for(int i = 0; i < 12;i++){
                if(t.at(i).isOcc()){
                    t.at(i).getPlane().setFuel_Level(t.at(i).getPlane().getFuel_Level()+50);
                }
            }
        }
        
        void addRandomPlane(){
            static int seed_num = time(NULL);  //holds the seed in the function every time airport runs we will get a radom new plane
            w.resize(w.size()+1);
            w.at(w.size()-1) = plane(seed_num);
            seed_num++;
        }
        
        void removePlane(int wait){
            w.erase(w.begin() + (wait-1));
        }
        
        vector<plane> getWaitlist(){
            return w;
        }
        vector<bool> getRunway(){
            vector<bool> temp(r.size());
            for(int i = 0; i < r.size(); i++){
                temp.at(i) = r.at(i).isOcc();
                //cout << temp.at(i);
            }
            return temp;
        }
        vector<bool> getTerminal(){
            vector<bool> temp(12);
            for(int i = 0; i < t.size(); i++){
                temp.at(i) = t.at(i).isOcc();
            }
            return temp;
        }

        vector<bool> getFuel(){
            vector<bool> temp(12);
            for(int i = 0; i < t.size(); i++){
                if(t.at(i).isOcc()){
                    if(t.at(i).getPlane().getFuel_Level() >= 1000){
                        temp.at(i) = true;
                    }else{
                        temp.at(i) = false;
                    }
                }else{
                    temp.at(i) = false;
                }
            }
            return temp;
        }

        void action(){
            refuel();
            for(int i = 0; i < 3; i++){
                cout << "_" << endl;   //for some reason for windows applications this stops the glitching, it only works here...
                if(r_time.at(i) > 0){
                    r_time.at(i)--;
                }else if(r_time.at(i) == 0){
                    landTerminal(i+1, t_time.at(i));
                    r_time.at(i) = -1;
                }
                if(r_time_ts.at(i) > 0){
                    r_time_ts.at(i)--;
                }else if(r_time_ts.at(i) == 0){
                    removeFromRunway(t_time_ts.at(i)+1);//remove plane from terminal here
                    r_time_ts.at(i) = -1;
                }
                if(r_clean.at(i) > 0){
                    r_clean.at(i)--;
                }else if(r_clean.at(i) == 0){
                    if(!fireKilled){now_clean(i+1);}
                    r_clean.at(i) = -1;
                }
            }
            for(int i = 0; i < w.size(); i++){
                w.at(i).setFuel_Level(w.at(i).getFuel_Level()-2);
                if(w.at(i).getFuel_Level() <= 0){
                    planes_crashed++;
                    removePlane(i+1);
                }
            }
            for(int i = 0; i < 12; i++){
                if(t_clean.at(i) > 0){
                    t_clean.at(i)--;
                }else if(t_clean.at(i) == 0){
                    now_clean(i+1);
                    t_clean.at(i) = -1;
                }
            }
            
        }

        int getCrashed(){
            return planes_crashed;
        }
        
        
    
        
    private:
        vector<location> r;
        vector<int> r_time;
        vector<int> r_time_ts;
        vector<location> t;
        vector<int> t_time;
        vector<int> t_time_ts;
        vector<plane> w;
        vector<int> r_clean;
        vector<int> t_clean;
        int planes_crashed;
        bool fireDispached;
        bool fireKilled;
};

