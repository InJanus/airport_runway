
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

class plane{
    public:
        plane(int seed){
            srand (seed);     //this is for random genaration to set the seed to random
            plane_name = genRandomName();
            //plane_name = plane_name + ((char)rand()%26+65);// + ((int)rand()%8999+1000);
            plane_size = rand()%3+1;
            fuel_level = rand()%898+100; 
            cargo_type = rand()%22+1;
            cargo_ammount = rand()%999+1;
        }
        
        plane(){
            srand (time(NULL));     //this is for random genaration to set the seed to random
            plane_name = genRandomName();
            //plane_name = plane_name + ((char)rand()%26+65);// + ((int)rand()%8999+1000);
            plane_size = rand()%3+1;
            fuel_level = rand()%898+100;
            cargo_type = rand()%22+1;
            cargo_ammount = rand()%999+1;
        }
        
        
        
        plane(string plane_name, int plane_size, double fuel_level, int cargo_type, int cargo_ammount){
            srand (time(NULL));
            this->plane_name = plane_name;
            this->plane_size = plane_size;
            this->fuel_level = fuel_level;
            this->cargo_type = cargo_type;
            this->cargo_ammount = cargo_ammount;
        }
        
        string genRandomName(){
            string temp;
            temp = (char)(rand()%26+65);
            temp = temp + (char)(rand()%26+65);
            temp = temp + (char)(rand()%10+48);
            temp = temp + (char)(rand()%10+48);
            temp = temp + (char)(rand()%10+48);
            temp = temp + (char)(rand()%10+48);
            return temp;
        }
        
        void genNewPlane(){
            plane_name = genRandomName();
            plane_size = rand()%3+1;
            fuel_level = rand()%898+100;
            cargo_type = rand()%3+1;
            cargo_ammount = rand()%999+1;
        }
        string getPlane_Menu(int pos){
            //stringstream ss;
            //string spos;
            //string fuel_levels;
            //ss << pos;
            //ss >> spos;
            //ss<<fuel_level;
            //ss>>fuel_levels;
            string temp;
            if(fuel_level < 10){
                temp = to_string(pos) + " : " + plane_name + " :   " + to_string(fuel_level) + " : " + getCargo_Type(); 
            }else if(fuel_level < 100){
                temp = to_string(pos) + " : " + plane_name + " :  " + to_string(fuel_level) + " : " + getCargo_Type(); 
            }else{
                temp = to_string(pos) + " : " + plane_name + " : " + to_string(fuel_level) + " : " + getCargo_Type();
            }
            return temp;
        }
        
        friend ostream& operator<<(ostream &output, plane &p){
            output << "Name: " << p.plane_name << endl << "Fuel Level: " << p.fuel_level;
            return output;
        }
        
        string getPlane_Name(){
            return plane_name;
        }
        
        int getPlane_Size(){
            return plane_size;
        }
        int getFuel_Level(){
            return fuel_level;
        }
        string getCargo_Type(){
                    //for cargo type
        //1 = people
        //2 = goods
        //3 = Military Supplies
            switch(cargo_type){
                case 1:
                    return "People";
                case 2:
                    return "Goods";
                case 3:
                    return "Military Supplies";
                case 4:
                    return "Human Remains";
                case 5:
                    return "Drugs";
                case 6:
                    return "The President";
                case 7:
                    return "Dogs";
                case 8:
                    return "Rail-Road Supplies";
                case 9:
                    return "Cats";
                case 10:
                    return "Food";
                case 11:
                    return "Snakes";
                case 12:
                    return "Lamas";
                case 13:
                    return "FireWorks";
                case 14:
                    return "Goats";
                case 15:
                    return "Black Market Goods";
                case 16:
                    return "The Devil";
                case 17:
                    return "Cat Food";
                case 18:
                    return "Dog Food";
                case 19:
                    return "Beer";
                case 20:
                    return "Vodkia";
                case 21:
                    return "Rum";
                case 22:
                    return "Space Pirates";
                case 23:
                    return "Pirates";

                    

            }
        }
        
        int getCargo_N(){
            return cargo_type;
        }
        int getCargo_Ammount(){
            return cargo_ammount;
        }
        
        void setPlane_Name(string name){
            plane_name = name;
        }
        void setPlane_Size(int size){
            plane_size = size;
        }
        void setFuel_Level(int fuel){
            fuel_level = fuel;
        }
        void setCargo_Type(int type){
            cargo_type = type;
        }
        void setCargo_Ammount(int ammount){
            cargo_ammount = ammount;
        }
        
        //need some kind of level system
        //size 1 plane cant hold more than 15 people, 20 goods, no military suplies
        //size 2 plane cant hold more than 50 people, 70 goods, no military suplies
        //size 3 plane cant hold more than 100 people, 150 goods, 30 military suplies
        
        
        

    private:
        string plane_name;
        int plane_size;
        int fuel_level;
        int cargo_type;
        int cargo_ammount;
};


/*
int main(){
    //srand (time(NULL));
    vector<plane> p(10);
    //plane p1;
    //plane p2, p3;
    
    //due to cloud 9 capabilities, if you use srand time it gets the same time from all the same ones. due to this, i need to use a seed
    
    //cout << p1 << endl << p2 << endl << p3 << endl;
    
    for(int i = 0; i < 10; i++){
        p.at(i) = plane(i); //i will be the seed
        cout << p.at(i).getPlane_Menu(i) << endl << endl;
    }
    
    
    
}
*/

