#include <bits/stdc++.h>
using namespace std;

int main()
{
   int q;
   cin>>q;
   while(q--){
   int P,H;
   long hp;
     cin>>hp>>P>>H;
     while(P){
         if(hp<=0)
             break;
         hp=floor(hp/2)+10;
         P--;

     }
     while(H){
         if(hp<=0)
             break;
         hp=hp-10;
         H--;
     }
     if(hp<=0)
         cout<<"YES\n";
     else
         cout<<"NO\n";
   }
    return 0;
}
