#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<time.h>
#include<conio.h>
using namespace std;

void swap(int *a,int *b,int *c)
{
	srand(time(0));
	int t;
	int x=1+rand()%100;
	for(int i=0;i<x;i++)
	{
		t=*b;
		*b=*a;
		*a=*c;
		*c=t;
	}
}
int main()
{
    cout<<"\n\t\t\t***************THE SWAP CARD GAME***************\n\n"<<endl;
    srand(time(0));
	int x,y,z,a,b,c,flag=0,g,x1,z1,y1;
	x=1+rand()%13;
	y=1+rand()%13;
	z=1+rand()%13;
	x1=1+rand()%4;
	x1=1+rand()%4;
	x1=1+rand()%4;
	cout<<"\t\t\t\t\tThe Cards are:"<<endl<<"\t\t\t\t\tx= "<<x<<" y= "<<y<<" z= "<<z<<endl<<endl;
	cout<<"\t\t\t\t\tEnter any key to swap the cards: \n";
	if(getch())
	{
		swap(&x,&y,&z);
		cout<<endl<<"\t\t\t\t\tNow Guess the values of x,y,z\n"<<endl;
		do{
		cin>>a>>b>>c;
		if(x==a && y==b && z==c)
		{
			cout<<"\t\t\t\t\tYOU WIN !!!"<<endl;
			flag=1;
		}
		else
			cout<<"\t\t\t\t\tWRONG GUESS ! TRY AGAIN!!!"<<endl;
		}while(flag!=1);
	}
}
