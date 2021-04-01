#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>
class BUS
{
	int busno;
	char source[30];
	char destination[30];
	char type[30];
	public:
	void getdata()
	{
		cout<<"\nBus no:\t";
		cin>>busno;
		cout<<"Destination:\t";
		gets(destination);
		cout<<"Source:\t";
		gets(source);
		cout<<"Type :\t";
		gets(type);

	}
	void modify()
	{
	cout<<"\nBus No:\t"<<busno <<"\tDestination:\n"<<destination<<endl;
	cout<<"Source:\t"<<source<<"\tType:\t"<<type<<endl;
	cout<<"Enter new details.";
	char ds[30],src[30],tp[30];
	int bn;
	cout<<"\nNew busno: (Enter '-1' to retain old one)";
	cin>>bn;
	cout<<"New destination: (Enter '.' to retain old one)";
	gets(ds);
	cout<<"New source: (Enter '.' to retain old one)";
	gets(src);
	cout<<"New type: (Enter '.' to retain old one)";
	gets(tp);
	if(bn!=-1)
	busno=bn;
	if(strcmp(ds,".")!=0)
	strcpy(destination,ds);
	if(strcmp(src,".")!=0)
	strcpy(source,src);
	if(strcmp(tp,".")!=0)
	strcpy(type,tp);
	}
	void putdata()
	{
	cout<<"\nBus No\t"<<busno <<"\tDestination:\t "<<destination<<endl;
	cout<<"Source :\t"<<source<<"\tType:\t"<<type<<endl;
	}
	int getbusno()
	{
	return busno;
	}
}b1;
void main()
{
 clrscr();
 char ch,choice;

 do
 {
   cout<<"\na.New bus";
   cout<<"\nb.Display all busses";
   cout<<"\nc.Modify";
   cout<<"\nd.Exit.";
   cout<<"\nEnter your choice:\t";
   cin>>choice;
   switch(choice)
   {
   case 'a':
	ch='y';
	ofstream fo("bus.dat",ios::app|ios::binary);
	if(!fo)
	{
	cout<<"\nCould not open file";
	getch();
	exit(0);
	}
	 cout<<"\nEnter Busdetail:";
	 b1.getdata();
	 fo.write((char *)&b1,sizeof(b1));
	 fo.close();
	 break;
   case 'b':

	 cout<<"\nNow records display as:\n";
	ifstream fi("bus.dat",ios::in|ios::binary);
	if(!fi)
	{
	cout<<"\nCould not open file";
	getch();
	exit(0);
	}
	fi.seekg(0);
	while(!fi.eof())
	 {
	  fi.read((char *)&b1,sizeof(b1));
	  if(fi.eof())
	  break;
	  b1.putdata();
	 }
	 fi.close();
	 break;
   case 'c':
	 cout<<"\nModification:\n";
	 fstream fio("bus.dat",ios::in|ios::out|ios::binary);
	if(!fio)
	{
	cout<<"\nCould not open file";
	getch();
	exit(0);
	}

	 int bn;
	 char found;
	 cout<<"\nEnter bus no :\t";
	 cin>>bn;
	 int pos;
	 while(!fio.eof())
	 {
	    pos= fio.tellg();
	    fio.read((char*)&b1,sizeof(b1));
	    if(b1.getbusno()==bn)
	    {
	       b1.modify();
	       fio.seekg(pos);
	       fio.write((char *)&b1,sizeof(b1));
	       found='t';
	       break;
	    }
	 }
	 if(found =='f')
	 cout<<"Record not found !!!\n";

	 fio.close();
	 break;
  case 'd':
	exit(0);
 default:
 cout<<"\nWrong choice";
 }
 cout<<"\nWant to repeat(y/n):\t";
 cin>>ch;
 }while(ch=='y'||ch=='Y');
 getch();
 }
