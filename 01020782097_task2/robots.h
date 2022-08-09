#ifndef ROBOTS_H
#define ROBOTS_H
#include <iostream>
#include <string.h>

using namespace std;
class Robots
{
private:
    char name[100];

    int function_id;
    int priceperday;
    std:: string datesrented[100];
    string inputdate;
    int d=0,robotsnumber=0;
public:
    bool rented=false;
    void addrobot();
    void addrobotmanual(string x,int y,int z);
    void getrobot();
    string getrobotname();
    void adddate(string inputdate);
    string getdate(string inputdate);

    Robots();
};

#endif // ROBOTS_H
