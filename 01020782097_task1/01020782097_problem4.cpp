#include <bits/stdc++.h>
using namespace std;

int main()
{
   int q;
   cin>>q;
   while(q--){
       int N,counter=0,temp;
       cin>>N;
       int h[N],answer[N];
       for(int i=0;i<N;i++){
           cin>>h[i];
       }

       for(int i=0;i<N;i++){
           temp=i+1;
           for(int j=i+1;j<N;j++){
               if(j==i+1){
                   counter++;
               }
               if(h[i]<h[i-1]&&h[i]<h[i+1]){
                   break;
               }
              if(h[j]>h[temp]){
                  counter++;
                  temp=j;
              }

           }
           answer[i]=counter;
           counter=0;
       }
       for(int i=0;i<N;i++){
           cout<<answer[i]<<" ";
           if(i==N-1)
               cout<<"\n";
       }



   }
    return 0;
}
