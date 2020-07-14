#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
int pos=0;
struct food
{int sno, cost;
char name[20], diet[10];
};
void choosebysnoo(food f[20]);
void choosebynameo(food f[20]);
void choosebydieto(food f[20]);
void takeorder(food f[20]);
void choosebysno(food f[20]);
void choosebyname(food f[20]);
void additem(food f[20]);
void removeitem(food f[20]);
void displaymenu(food f[20]);
void main()
{clrscr();
food f[20];
int n, ch;
cout<<"Enter the no. of items to be added"<<endl;
cin>>n;
cout<<"\nEnter sno, food item, cost and diet"<<endl;
for(int i=0; i<n; i++)
	{cin>>f[pos].sno>>f[pos].name>>f[pos].cost>>f[pos].diet;
	pos++;
	}
clrscr();
do
	{cout<<"\nMenu:-"<<endl;
	 cout<<"1. Take Order"<<endl;
	 cout<<"2. Add item"<<endl;
	 cout<<"3. Remove item"<<endl;
	 cout<<"4. Display menu"<<endl;
	 cout<<"5. Exit"<<endl;
	 cout<<"Choose your option"<<endl;
	 cin>>ch;
	 switch (ch)
		{case 1: takeorder(f);
			break;
		 case 2: additem(f);
			break;
		 case 3: removeitem(f);
			break;
		 case 4: displaymenu(f);
			break;
		 default: cout<<"Exit"<<endl;}
	}while (ch<=4);
getch();
}
void takeorder(food f[20])
{int ch;
do
	{cout<<"\nMenu:-"<<endl;
	 cout<<"1. Choose by sno"<<endl;
	 cout<<"2. Choose by item name"<<endl;
	 cout<<"3. Choose by diet"<<endl;
	 cout<<"4. Exit take order"<<endl;
	 cout<<"Enter your option"<<endl;
	 cin>>ch;
	 switch (ch)
		{case 1: choosebysnoo(f);
			break;
		 case 2: choosebynameo(f);
			break;
		 case 3: choosebydieto(f);
			break;
		 default: cout<<"Exit Take order"<<endl;
		 }
	}while(ch<=3);
}
void choosebysnoo(food f[20])
{int ch, sum=0, p=0;
char a;
do
	{cout<<"\nEnter the sno"<<endl;
	 cin>>ch;
	 for(int i=0; i<pos; i++)
		if (f[i].sno==ch)
			{cout<<f[i].sno<<"\t"<<f[i].name<<"\t"<<f[i].cost<<"\t"<<f[i].diet<<endl;
			 sum+=f[i].cost;
			 p=1;
			 break;
			 }
	 if(p==0)
		{cout<<"Invalid sno"<<endl;
			break;
		}
	 cout<<"\nDo you want to purchase more items?"<<endl;
	 cin>>a;
	}while(a=='y');
cout<<"\nTotal cost is "<<sum<<endl;
}
void choosebynameo(food f[20])
{int sum=0, p=0;
char ch[20], a;
do
	{cout<<"\nEnter the name"<<endl;
	 cin>>ch;
	 for (int i=0; i<pos; i++)
		if (strcmpi(f[i].name,ch)==0)
			{cout<<f[i].sno<<"\t"<<f[i].name<<"\t"<<f[i].cost<<"\t"<<f[i].diet<<endl;
			 sum+=f[i].cost;
			 p=1;
			 break;
			 }
	 if(p==0)
		cout<<"Invalid item name"<<endl;
	 cout<<"\nDo you want to add more items?"<<endl;
	 cin>>a;
	}while(a=='y');
cout<<"\nThe total cost is "<<sum<<endl;
}
void choosebydieto(food f[20])
{int sum=0, number, p=0;
char ch[10], a;
do
	{cout<<"\nEnter the diet"<<endl;
	 cin>>ch;
	 for(int i=0; i<pos; i++)
		if(strcmpi(f[i].diet,ch)==0)
			{cout<<f[i].sno<<"\t"<<f[i].name<<"\t"<<f[i].cost<<"\t"<<f[i].diet<<endl;
			 p=1;
			 }
	 if(p==1)
		{cout<<"\nChoose the sno of item you want"<<endl;
		 cin>>number;
		 for(int j=0; j<pos; j++)
			if(f[j].sno==number)
				{sum+=f[j].cost;
					break;
				}
		 }
	 if(p==0)
		cout<<"Invalid diet"<<endl;
	 cout<<"\nDo you want to add more items?"<<endl;
	 cin>>a;
	}while (a=='y');
cout<<"\nThe total cost is "<<sum<<endl;
}
void removeitem(food f[20])
{int ch;
do
	{cout<<"\nMenu:-"<<endl;
	 cout<<"1. Choose ny sno"<<endl;
	 cout<<"2. Choose by name"<<endl;
	 cout<<"3. Exit remove item"<<endl;
	 cout<<"Enter your option"<<endl;
	 cin>>ch;
	 switch (ch)
		{case 1: choosebysno(f);
			break;
		 case 2: choosebyname(f);
			break;
		 default: cout<<"Exit remove item"<<endl;
		 }
	}while(ch<=2);
}
void choosebysno(food f[20])
{char a;
do
	{cout<<"\nEnter the sno"<<endl;
	 int num;
	 cin>>num;
	 for (int p=0; p<pos; p++)
		if (f[p].sno==num)
			for(int i=p; i<pos; i++)
				 f[i]=f[i+1];
	 pos--;
	cout<<"Deleted"<<endl;
	cout<<"\nDo you want to delete more items?"<<endl;
	cin>>a;
}while (a=='y');}
void choosebyname(food f[20])
{char a;
do
	{cout<<"\nEnter the item"<<endl;
	 char item[10];
	 cin>>item;
	 for(int p=0; p<pos; p++)
		if (strcmpi(f[p].name,item)==0)
			for(int i=p; i<pos; i++)
				 f[i]=f[i+1];
	 pos--;
	 cout<<"Deleted"<<endl;
	 cout<<"\nDo you want to delete more items?"<<endl;
	 cin>>a;
	}while (a=='y');
}
void additem(food f[20])
{char a;
do
	{
	int p=0;
	cout<<"\nEnter the sno"<<endl;
	 int no;
	 cin>>no;
	 for(int i=0; i<pos; i++)
		if(f[i].sno==no)
			{cout<<"\nsno is already taken"<<endl;
			p=1;
			cout<<"Do you wish to try again?"<<endl;
			cin>>a;}
	 if(p==0)
		{cout<<"\nEnter sno, name, cost & diet"<<endl;
		 cin>>f[pos].sno>>f[pos].name>>f[pos].cost>>f[pos].diet;
		 pos++;
		 cout<<"Added"<<endl;
		 cout<<"\nDo you want to add more items?"<<endl;
		 cin>>a;
		 }
	}while (a=='y');
}
void displaymenu(food f[20])
{for (int i=0; i<pos; i++)
	cout<<f[i].sno<<"\t"<<f[i].name<<"\t"<<f[i].cost<<"\t"<<f[i].diet<<endl;
}