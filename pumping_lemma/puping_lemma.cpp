
#include<iostream>
using namespace std;
int main()
{
    string lemma;
    getline(cin,lemma);
    string a,b;
     int i;
    for(i=0;i<lemma.size();i++)
    {
        if(lemma[i]=='^')
        {
            i++;
            while(lemma[i]!='n')
            {
                a+=lemma[i];
                i++;
            }
            break;
        }
    }
    for(; i<lemma.size();i++)
    {
        if(lemma[i]=='^')
        {
            i++;
            while( lemma[i]!='n')
            {
                b+=lemma[i];
                i++;
            }
            break;
        }
    }
    int x,y;
    if(a.size()==0) x=1;
    else x=stoi(a);
    if(b.size()==0) y=1;
    else y=stoi(b);
    cout<<x<<" "<<y<<endl;
    cout<<"enter the value of n: ";
    int n;
    cin>>n;
    string str;

    for(i=0;i<x*n;i++)
    {
        str+="0";
    }
    for(i=0;i<y*n;i++)
    {
        str+="1";
    }
    cout<<"if n="<<n<<"then the expression becomes:"<<str<<endl;
    string xpart,ypart,zpart;
    for(i=0;i<(x*n)/2;i++)
    {
         xpart+=str[i];
    }

    for(;i<x*n;i++)
    {
        ypart+=str[i];
    }
    for(;i<str.size();i++)
    {
        zpart+=str[i];
    }
    cout<<xpart<<" "<<ypart<<" "<<zpart<<endl;
    int k;
    int zerocount,onecount;
    for(k=1; ;k++)
    {
        zerocount=0,onecount=0;
        int flag=0;
         string newstr;
        if(k>1) ypart+=ypart;
        newstr=xpart+ypart+zpart;
        cout<<"if k="<<k<<"then the language becomes:"<<newstr<<endl;
        for(i=0;i<newstr.size();i++)
        {
            if(newstr[i]=='0' && flag==0)
            {
                zerocount++;
                if(newstr[i+1]=='1')
                flag=1;
            }
            if(flag==1 && newstr[i]=='1')
            {
                onecount++;
                if(newstr[i+1]=='0')
                flag=3;
            }
        }
        if(zerocount==onecount && newstr.size()==(zerocount+onecount))
        {
            cout<<"Regular"<<endl;
        }
        else
        {
            cout<<"The language is not regular"<<endl;
            break;
        }
    }
    return 0;
}
