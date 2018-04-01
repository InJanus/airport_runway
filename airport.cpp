
#include <vector>

#include "terminal.cpp"
#include "runway.cpp"

using namespace std;


class airport{
    public:
        airport(){
            r.resize(0);
            t.resize(0);
        }
        
        airport(int r_size, int t_size){
            r.resize(r_size);
            t.resize(t_size);
        }
        
        bool isRunwayOc(int pos){
            
        }
        
        bool isTerminalOc(int pos){
            
        }
    
    
    private:
        vector<runway> r;
        vector<terminal> t;
};

int main(){
    
    
    return 0;
}