#ifndef USERS_H
#define USERS_H
#include <iostream>
#include <string.h>

using namespace std;
class Users
{
public:
    char name[100];
    int telephonenumber;
    string email;
    string inputdate;
    std::string robotsrented[100];
    std::string datesrented [100];
    int d=0;
    int robotsrentednumber=0;
public:
    void robotsrentedin(string x);
    void robotsrentedout();
    void addusermanual(string x,int y,string z);
    void adduser();
    void getuser();
    string getusername();
    void adddate(string inputdate);
    Users();
};

#endif // USERS_H
