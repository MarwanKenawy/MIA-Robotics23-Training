#include <bits/stdc++.h>
using namespace std;

int main()
{
    for(int i=1;i<=5;i++){
        if(i==1||i==5){
            cout<<" *    *  *****\n";
        }
        else if(i==3){
            cout<<" ******    *  \n";
        }
        else
            cout<<" *    *    *  \n";
    }
    return 0;
}
