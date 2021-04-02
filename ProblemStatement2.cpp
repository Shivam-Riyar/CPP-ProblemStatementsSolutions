/* PROGRAM TO KEEP COUNT OF CREATED OBJECTS USING STATIC MEMBERS */

#include<iostream.h>
#include<conio.h>
using namespace std;
class X
{ private: int codeno;
float price;
static int count;
public: void getval(int i,float j)
{
codeno=i;
price=j;
++count;
}
void display(void)
{
cout&lt;&lt;&quot;\n CODE NO : &quot;&lt;&lt;codeno&lt;&lt;&quot;\t&quot;;
cout&lt;&lt;&quot;\n PRICE : &quot;&lt;&lt;price&lt;&lt;endl;
}
static void dispcount(void)
{ cout&lt;&lt;&quot;\n COUNT : &quot;&lt;&lt;count&lt;&lt;endl; }
};
int X::count=0;
void main()
{ clrscr(); X ob1,ob2,ob3;
ob1.getval(101,25.12);
ob2.getval(102,38.19);
X::dispcount();
ob3.getval(103,49.00);
X::dispcount();
ob1.display(); ob2.display(); ob3.display();
getch();

}
