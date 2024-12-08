#include<bits/stdc++.h>
using namespace std;
int board[15];
int total_solution;

bool check_safe(int row,int col)//check if placing queen at row,col is safe
{
    for(int i=0;i<row;i++)
    {
        //if queen in the same column or diagonals (not safe)
        if(board[i]==col ||(board[i]-col==row-i)||(col-board[i]==row-i)) return false;
    }
    return true;//if safe
}

void find_solution(int row,int n)//find solution for placing queeen
{
    if(row==n)//all queen are placed
    {
    total_solution++;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i]==j) cout<<"Q"; //queen in current cell print Q
            else cout<<".";
        }
        cout<<endl;//move to next line after complete row
    }
    cout<<endl;//Leave a blank line after solution
    return;
    }

    for(int col=0;col<n;col++)//try to place queen in each column
    {
        if(check_safe(row,col))//if safe
        {
            board[row]=col;//place queen
            find_solution(row+1,n);//recursive call for next row
        }
    }

}
int main()
{
    int n;cin>>n; //Take input
    total_solution=0; //initialize solution (count)
    find_solution(0,n); // start find solution
    cout<<"Total Solutions: "<<total_solution<<endl;
    return 0;
}
