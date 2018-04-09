
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
            people_lost = 0;
            goods_lost = 0;
        }
        
        airport(int r_size, int t_size){
            r.resize(r_size);
            t.resize(t_size);
            w.resize(0);
            planes_crashed = 0;
            people_lost = 0;
            goods_lost = 0;
        }
        
        
        
        void landPlane(int wait, int run){
            plane temp = w.at(wait-1);
            removePlane(wait);
            r.at(run-1).addPlane(temp);
        }
        
        void landTerminal(int run, int term){
            plane temp = r.at(run-1).getPlane();
            r.at(run-1).removePlane();
            t.at(term-1).addPlane(temp);
        }
        
        void takeoff(int term, int run){
            plane temp = t.at(term-1).getPlane();
            t.at(term-1).removePlane();
            r.at(run-1).addPlane(temp);
        }
        
        void removeFromRunway(int run){
            r.at(run-1).removePlane();
        }
        
        void getCommand(string command){
            string scom = "";
            int num1 = 0;
            int num2 = 0;
            
            istringstream input(command);
            
            input >> scom; 
            input >> num1;//this gets all of the commands and splits them up 
            input >> num2;
            
            if(scom == "land"){
                landPlane(num1,num2);
            }else if(scom == "terminal"){
                landTerminal(num1,num2);
            }else if(scom == "takeoff"){
                takeoff(num1,num2);
            }else if(scom == "ton"){
                removeFromRunway(num1);
            }
            
            //cout <<scom << endl << num1 << endl << num2 << endl << num3 << endl;
            
            
            
        }
        
        void refuel(){
            for(int i = 0; i < 12;i++){
                
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
        
        
    
        
    private:
        vector<location> r;
        vector<location> t;
        vector<plane> w;
        int planes_crashed;
        int people_lost;
        int goods_lost;
};

int main(){
    
    airport myairport = airport(3,12); //one runway 3 terminals
    myairport.addRandomPlane();
    myairport.addRandomPlane();
    
    //graphics_airport g_air = graphics_airport("CVG Airport",myairport.getRunway(),myairport.getTerminal());
    
    vector<plane> inputp(0);
    vector<bool> runway(3);
    vector<bool> terminal(12);
    string temp;
    
    inputp = myairport.getWaitlist();
    runway = myairport.getRunway();
    terminal = myairport.getTerminal();
    
    graphics_airport g_air("CVG Airport",inputp,runway,terminal);
    
    //myairport.landPlane(1,1);
    //myairport.landTerminal(1,1);
    //myairport.takeoff(1,2);
    //myairport.removeFromRunway(2);
    
    for(;;){
        if((int)(rand()%8+1) == 1){
            myairport.addRandomPlane();
        }
            
        temp = getFileCommand("command_here.txt");
        clearFile("command_here.txt");
        myairport.getCommand(temp);
        inputp = myairport.getWaitlist();
        runway = myairport.getRunway();
        terminal = myairport.getTerminal();
        myairport.refuel();
        g_air.setData(inputp, runway, terminal);
        g_air.repaint();
        cout << g_air;
        pause(1);
        
    }
    
    
    
    

    
    
    
    //myairport.addRandomPlane();
    //test.addRandomPlane();
    //test.removePlane(2);
    //g_air.setWaitList(myairport.getWaitlist());
    //g_air.repaint();
    //cout << g_air;
    //cin.get();
    //test.landPlane(1,1);
    //test.getCommand("test 1 2 3");
    
    //string temp;
    //for(;;){
        //temp = getFileCommand("command_here.txt");
        //test.getCommand(temp);
        //clearFile("command_here.txt");
        
        //if((int)(rand()%8+1) == 1){
            //test.addRandomPlane();
        //}
        //test.getWaitlist();
        //pause(1);
    //}
    
    return 0;
    
    
}
