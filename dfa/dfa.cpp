#include<bits/stdc++.h>
using namespace std;
#define mx 100

int main()
{
    char state[mx],alpha[mx],start,finals,stat,paths[mx],p,str[mx];

    int st_no,al;
    cout<<"enter the no of state:"<<endl;
    cin>>st_no;
    cout<<"enter the state:"<<endl;
    for(int i=0;i<st_no;i++){
        cin>>state[i];
    }
    cout<<"enter the no of alphabet:"<<endl;
    cin>>al;
    for(int i=0;i<al;i++){
        cin>>alpha[i];
    }
     cout<<"enter the transition function:"<<endl;
    char transition[st_no][al];


    for(int i=0;i<st_no;i++){

        for(int j=0;j<al;j++){
            cout<<"from state "<<state[i]<<" by "<<alpha[j]<<endl;
            cin>>transition[i][j];

        }
    }
     cout<<"enter the start state: ";
     cin>>start;
     cout<<"enter the final state: ";
     cin>>finals;
     cout << "Enter the string: ";
     cin >> str;

     stat=start;
     int path=1;
     paths[0]=start;
     for(int i=0;str[i];i++){
        for(int j=0;j<al;j++){
            if(str[i]==alpha[j]){
                stat=transition[stat-start][j];
                break;
            }
        }
        paths[path++]=stat;
     }

     if(stat==finals){
        cout<<"accepted";
     for(p=0;p<path;p++){
        cout<<paths[p]<<"-";
     }
     }else {
     cout<<"not accepted";
     }
return 0;
}
