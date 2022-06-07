//N_Queen.cpp
#include<bits/stdc++.h>
using namespace std;
void print(int board[][20],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]!=1)
            {
                board[i][j]=0;
            }
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    return ;
}

bool checker(int board[][20],int n,int row,int j)
{         //"j" index of box where attempt to place Queen
    for(int i=0;i<row;i++) //checkin for column
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    for(int m=0;m<row;m++)//checking for diagonals
    {
        for(int o=0;o<n;o++ )
        {
            if(o<j && (m-o)==(row-j))//normal diagonal
            {
                if(board[m][o]==1)
                {
                    return false;
                }
            }
            else if(o>j && (m+o)==(row+j))
            {
                if(board[m][o]==1)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int count=0;
bool nQueen(int board[][20],int n,int i=0)
{
    //base case
    if(i==n)
    {
        //print(board,n);
        ::count++;
        return true;
    }
    //rec case
    //try to place queen in every box and check wheather can be placed or not
    for(int j=0;j<n;j++)
    {
        if(checker(board,n,i,j))//if possible
        {
            board[i][j]=1;
            bool success=nQueen(board,n,i+1);
            // if(success)//this part terminates function again and again as true found to directly stop 
            //by removing this function will not stop after finding a valid solution
            // {
            //     return true;
            // }
        }
        //backtracking
        board[i][j]=0;
    }
    //if this loop is completed sucessfully that means there ain't right place in that row to put a Queen so return and then correct position of 
    //Queen in previous row
    return false; 
}
int main()
{
    int board[20][20];
    int n;
    cin>>n;
    nQueen(board,n);
    cout<<(::count)<<"\n";
    return 0;
}