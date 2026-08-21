#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
	int n,lost;

	cout<<"Enter number of frames= ";
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cout<<"\n sender:sending frame "<<i<<endl;
		cout<<"Timer started..."<<endl;
		sleep(2);
		if(i==4)
		{
			cout<<"Frame "<< i<<" is lost"<<endl;
			cout<<"Timer expired"<<endl;
			cout<<"Sender : Resending frame "<<i<<endl;
			sleep(2);
			cout<<"Reciver : frame "<<i<<" received"<<endl;
		    cout<<"Receiver sending Ack "<<i<<endl;
	     	cout<<"sender: Ack "<<i<<" received"<<endl;
		    cout<<"timer stopped"<<endl;
     	}
     	else
     	{
     		cout<<"Receiver:frame "<<i<<" received"<<endl;
     		cout<<"Receiver sending ACK "<<i<<" received"<<endl;
			sleep(1);
			cout<<"Sender:ACK "<<i<<"received"<<endl;
			cout<<"Timer stopped"<<endl;		 
			}
	}
	cout<<"\nAll frames transmitted successfully"<<endl;
	return 0;
}
