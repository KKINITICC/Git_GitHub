#include<bits/stdc++.h>
using namespace std;
//here logic is that with each char only two options were there present/absent
// faith was f(bc) gives ["","b","c","bc"] so f(abc)=a+f(bc) +f(bc);
vector<string> print_substring(string str)
{
    if(str.size()==0)
    {
        vector<string> list;
        list.push_back("");
        return list;
    }
    char first=str[0];//abc
    string sub=str.substr(1);//bc
    vector<string> list=print_substring(sub);//["","b","c","bc"];
    int n=list.size();
    for(int i=0;i<n;i++)
    {
        list.push_back(first+list[i]);
    }
    return list;
}
void print(vector<string> arr)//printing a vector
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<",";
    }
}

int main()
{
    string str="abhishek";
    print(print_substring(str));
    return 0;
}