#include<iostream>
using namespace std;
void initialize(int grid[1000][1000],int k,int l)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<l;j++)
        grid[i][j]=0;
    }
}
bool is_safe(int grid[1000][1000],int row,int col,int k,int l)
{
    //to check row
    for(int i=0;i<k;i++)
     {
         if(grid[row][i]==1)
         return false;
     }
     //to check col
     for(int j=0;j<l;j++)
     {
         if(grid[j][col]==1)
         return false;
     }
     int i=row,j=col;
     //to check left down diagonals
     while(true)
     {
         if(grid[i][j]==1)
         {
         return false;
         break;
         }
         i++;
         j--;
         if(i>k-1||j<0)
         break;

     }
     i=row;j=col;
     //to check right down diagonals
     while(true)
     {
            if(grid[i][j]==1)
         {
         return false;
         break;
         }
         i++;
         j++;
         if(i>k-1||j>k-1)
         break;
     }
     i=row;j=col;
     //to check left up diagonal
     while(true)
     {
           if(grid[i][j]==1)
         {
         return false;
         break;
         }
         i--;
         j--;
         if(i<0||j<0)
         break;
     }
     i=row;j=col;
     //to check right up diagonal
     while(true)
     {
           if(grid[i][j]==1)
         {
         return false;
         break;
         }
         i--;
         j++;
         if(i<0||j>k-1)
         break;
     }
     return true;
}
bool solfound(int grid[1000][1000],int k,int l)
{
    int a=0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<l;j++)
        {
            if(grid[i][j]==1)
            a++;
        }
    }
    if(a==k)
    return true;
    else
    return false;
}
bool sol(int grid[1000][1000],int k,int l)
{
if(solfound(grid,k,l))
return true;
for(int  i=0;i<k;i++)
{
    for(int j=0;j<l;j++)
    {
        if(is_safe(grid,i,j,k,l))
        {
            grid[i][j]=1;
            if(sol(grid,k,l))
            return true;
            grid[i][j]=0;
        }
    }
}
return false;
}
void draw(int grid[1000][1000],int k,int l)
{
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<l;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"enter number of row and col:"<<endl;
    int i,j;
    cin>>i>>j;
    int grid[1000][1000];
    initialize(grid,i,j);
    sol(grid,i,j);
    draw(grid,i,j);
    return 0;

}