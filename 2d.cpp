#include<iostream>
using namespace std;
int main()
{
int a1[3][3];
int a2[3][3]={{1,1,1},{1,1,1},{1,1,1}};
int a3[3][3];
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
    cout<<a2[i][j]<<" ";
}
cout<<endl;
}
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{ 
    cin>>a1[i][j];
        if (i==j)
    {     
    a1[i][j]+=a2[i][j];}
}
}
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{ 
    cout<<a1[i][j];
   
}
    for ( int i=0; i<5; i++)
        cout<<endl;
}
}
