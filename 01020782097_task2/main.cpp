#include <iostream>
#include "robots.h"
#include "users.h"
using namespace std;

int main()
{
   Robots r[100];
   r[0].addrobotmanual("cleaner",1,55);
   r[1].addrobotmanual("driver",2,60);
   r[2].addrobotmanual("cook",3,65);


   Users u[100];
   u[0].addusermanual("Harry",010,"harry@gmail.com");
   u[1].addusermanual("Hermione",011,"hermione@yahoo.com");
   u[2].addusermanual("Ron",012,"ron@gmail.com");


   int trobots=3,tusers=3,option=0,counter=1;
   cout<<"WELCOME ADMIN TO ROBOT RENTAL!\nMAIN MENU:\n";
   while(counter){
       cout<<"\t1 - ADD ROBOT\n\t2 - ADD USER\n\t3 - DISPLAY ALL USERS\n\t4 - DISPLAY ALL ROBOTS\n\t5 - SEARCH FOR ROBOT BY NAME\n\t6 - SEARCH FOR USER BY NAME\n\t7 - RENT ROBOT\n\t8 - EXIT\n";

   cin>>option;

   switch(option){
   case 1:{
       int n=0;
       cout<<"Enter number of robots"<<endl;
       cin>>n;
       for(int i=0;i<n;i++){
           r[trobots].addrobot();
            trobots++;
       }
       }
       break;
   case 2:{
       int n=0;
       cout<<"Enter number of users"<<endl;
       cin>>n;
       for(int i=0;i<n;i++){
           u[tusers].adduser();
           tusers++;}

       }
       break;
   case 3:{
       for(int i=0;i<tusers;i++){
           u[i].getuser();
               cout<<"robots rented:";
           u[i].robotsrentedout();
           cout<<endl;
       }

   }
       break;
   case 4:{
       for(int i=0;i<trobots;i++){
           r[i].getrobot();
       }
       break;
   }
   case 5:{
       string input;
       cout<<"Enter Robot Name: ";
       cin>>input;
       for(int i=0;i<trobots;i++){
           if(r[i].getrobotname()==input){
               cout<<"found\n";
               r[i].getrobot();
               cout<<"\n";
           }else{cout<<"not found\n";}
           }

       }
       break;
case 6:{
       int flag=0;
       string input;
       cout<<"Enter user Name: ";
       cin>>input;
       for(int i=0;i<trobots;i++){
           if(u[i].getusername()==input){
               cout<<"found\n";
               u[i].getuser();
               cout<<"\n";
               flag=1;
               break;
           }
       }if(flag==0)
           cout<<"not found\n";
   }
       break;
   case 7:{
       //rent robot to user
       int tempuser,temprobot,flag=0;
       for(int i=0;i<tusers;i++){
           cout<<i<<" - ";
           u[i].getuser();
       }
       cout<<"select user: ";
       cin>>tempuser;
       cout<< "add date in format (day/month/year): ";
       string inputdate;
       cin>>inputdate;
       cout<<"available robots:\n";
       for(int j=0;j<trobots;j++){
           if(r[j].getdate(inputdate)=="available"){
               cout<<j<<" - ";
            r[j].getrobot();
            flag=1;
           }
       }
           if(flag==1){cout<<"select robot:";
               cin>>temprobot;
               r[temprobot].rented=true;
               r[temprobot].adddate(inputdate);
               u[tempuser].adddate(inputdate);
               u[tempuser].robotsrentedin(r[temprobot].getrobotname());
               cout<<"rented successfully\n";

           }
             else{  cout<<"unavailable\n";}

   }
       break;
   case 8:{
       counter=0;
   }
       break;
   default:{
       cout<<"error\n";
}

   }
   }



    return 0;
}
