#include <iostream>
#include <map>
using namespace std;

int main()
{
   int q;
   cin>>q;
   while(q--){
     map <char,char> m1;
     map <char,char> m2;
     map <char,char> m3;
     m1['1']='a';
     m1['2']='b';
             m1['3']='c';
             m1['4']='d';
             m1['5']='e';
             m1['6']='f';
             m1['7']='g';
             m1['8']='h';
             m1['9']='i';
             m2['0']='j';
             m2['1']='k';
             m2['2']='l';
             m2['3']='m';
             m2['4']='n';
             m2['5']='o';
             m2['6']='p';
             m2['7']='q';
             m2['8']='r';
             m2['9']='s';
             m3['0']='t';
             m3['1']='u';
             m3['2']='v';
             m3['3']='w';
             m3['4']='x';
             m3['5']='y';
             m3['6']='z';
             std::map<char,char>::iterator it;
             string s;
             string ans;
             cin>>s;
            int len=s.length();
            int k=0;
             for(int i=len-1;i>=0;){
                    if(s[i]=='&'){
                        if(s[i-2]=='1'){
                            it=m2.begin();
                           for(int j=0;j<10;j++){
                            if(s[i-1]==it->first){
                                //cout<<it->second;
                                //cout<<len-1-i;
                                ans[k]=it->second;
                                k++;
                                i=i-3;
                                break;
                            }else{it++;}
                           }
                    }
                 else if(s[i-2]=='2'){
                    it=m3.begin();
                           for(int j=0;j<7;j++){
                            if(s[i-1]==it->first){
                                //cout<<it->second;
                                 ans[k]=it->second;
                                k++;
                                i=i-3;
                                break;
                            }else{it++;}
                           }
                 }
             }else{char temp=s[i];//cout<<m1[temp];
              ans[k]=m1[temp];
                                k++;;i--;}

   }
   for(int l=k-1;l>=0;l--){
    cout<<ans[l];
   }
   cout<<"\n";
   }

    return 0;
}
