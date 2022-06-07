#include<bits/stdc++.h>
using namespace std;

vector<string> mazepath(int sr,int er,int sc,int ec)
{
    vector<string> arr;
    if(sr==er && sc==ec)
    {
        arr.push_back("");
        return arr;
    }
    else if(sr==er)//if reached row then only only horizontal steps can be taken
    {
        string str;
        for(int i=0;i<(ec-sc);i++)
        {
            str='h'+str;
        }
        arr.push_back(str);
        return arr;
    }
    else if(ec==sc)//if reached column then only vertical steps can be taken
    {
        string str;
        for(int i=0;i<(er-sr);i++)
        {
            str='v'+str;
        }
        arr.push_back(str);
        return arr;
    }
    // expectation + faith---> f(m,n)= ('h'+f(m,n-1))+('v'+f(m-1,n))
    vector<string> pathrow=mazepath(sr+1,er,sc,ec);//| | row - 1
    int m=pathrow.size();  
    vector<string> pathcol=mazepath(sr,er,sc+1,ec);//col - 1
    int n=pathcol.size();
    for(int i=0;i<m;i++)//vertical
    {
        string str='v'+pathrow[i];
        arr.push_back(str);
    }
    for(int i=0;i<n;i++)//horizontal
    {
        string str='h'+pathcol[i];
        arr.push_back(str);
    }
    return arr;
}
int main()
{
    vector<string> arr=mazepath(0,2,0,2);
    cout<<"done";
    return 0 ;
}