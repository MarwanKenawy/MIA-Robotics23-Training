#include "robots.h"
#include <iostream>
#include <string.h>

using namespace std;
Robots::Robots()
{

}
void Robots::addrobot(){
    cout<<"Enter Name, fuction_id, price per day: ";
    cin>>name>>function_id>>priceperday;
}
void Robots::addrobotmanual(string x,int y,int z){
    int len=x.length();
    for(int i=0;i<len;i++)
   name[i]=x[i];
   function_id=y;
   priceperday=z;
}
void Robots::getrobot(){
    cout<<name<<","<<function_id<<","<<priceperday<<endl;
    for(int i=0;i<d;i++){
        if(i==0)
            cout<<"dates rented: ";
        cout<<datesrented[i]<<",";
    }
    cout<<endl;
}
string Robots::getrobotname(){
    return name;
    }
void Robots::adddate(string inputdate){
    datesrented[d]=inputdate;
    d++;
}
string Robots::getdate(string inputdate){
    for(int m=0;m<d;m++){
        if(inputdate==datesrented[m]){
            return "unavailable";

        }
    }
        return "available";
    }

