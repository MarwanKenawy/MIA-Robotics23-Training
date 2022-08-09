#include "users.h"
#include <iostream>
#include <string.h>

using namespace std;

Users::Users()
{

}
void Users::adduser(){
    cout<<"Enter Name, Telephone Number, Email: ";
    cin>>name>>telephonenumber>>email;
}
void Users::getuser(){
    cout<<name<<","<<telephonenumber<<","<<email<<endl;

}
string Users::getusername(){
    return name;
}
void Users::adddate(string inputdate){
    datesrented[d]=inputdate;
    d++;
}
void Users::addusermanual(string x,int y,string z){
    int len=x.length();
    for(int i=0;i<len;i++){
   name[i]=x[i];}
   telephonenumber=y;
   email=z;
}
void Users::robotsrentedin(string x){
    robotsrented[robotsrentednumber]=x;
    robotsrentednumber++;
}
void Users::robotsrentedout(){
    for(int i=0;i<robotsrentednumber;i++){
        cout<<robotsrented[i]<<endl;
    }
}
