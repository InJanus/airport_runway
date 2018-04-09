
#include <vector>
#include <sstream>

#include "plane.cpp"
//#include "terminal.cpp"
//#include "runway.cpp"
#include "command.cpp"


//using namespace std;



class airport{
    public:
        airport(){
            //r.resize(0);
            //t.resize(0);
            w.resize(0);
            planes_crashed = 0;
            people_lost = 0;
            goods_lost = 0;
        }
        
        airport(int r_size, int t_size){
            //r.resize(r_size);
            //t.resize(t_size);
            w.resize(0);
            planes_crashed = 0;
            people_lost = 0;
            goods_lost = 0;
        }
        
        void getWaitlist(){
            for(int i = 0; i < w.size(); i++){
                
            }
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
            
            cout <<scom << endl << num1 << endl << num2 << endl << num3 << endl;
            
            
            
            
            
            
            
            /*
            if((status == "T")||(status == "t")){
                if(w.at(num1) != NULL){
                    
                }else{
                    cout << "Waitlist: " << num1 << " DNE" << endl;
                }
            }else if((status == "L")||(status == "l")){
                
            }else{
                //no valid command
            }   
            */
        }
        
        void addRandomPlane(){
            static int seed_num = time(NULL);  //holds the seed in the function every time airport runs we will get a radom new plane
            w.resize(w.size()+1);
            w.at(w.size()) = plane(seed_num);
            seed_num++;
        }
        
        void getAirportStatus(){
            
        }
        
        bool isRunwayOc(int pos){
            
        }
        
        bool isTerminalOc(int pos){
            
        }
    
        
    private:
        //vector<runway> r;
        //vector<terminal> t;
        vector<plane> w;
        int planes_crashed;
        int people_lost;
        int goods_lost;
};

int main(){
    
    airport test = airport(1,3);
    
    test.getCommand("test 1 2 3");
    return 0;
}