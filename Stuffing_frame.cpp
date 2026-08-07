#include<iostream>
using namespace std;
int main()
{
    char a[50],b[100];
    int i,j;
    int count=0;
    cout<<"Enter input frame:";
    cin>>a;
    i=0;
    j=0;
    while(a[i]!='\0')
    {
        b[j]=a[i];
       
       
        if(a[i]=='1') 
           count++;
        else
           count=0;
        
        if(count==5)
        {
            j++;
            b[j]='0';
            count=0;
        }   
        i++;
        j++;
    }
    b[j]='/0';
    cout<<"stuffed frame:"<<b;
    return 0;
}