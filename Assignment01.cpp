// Name: Tahmeed Sadiq //
// ID: 22234103297 //
#include <iostream>
#include <math.h>
using namespace std;
class animal{
public:
long id;
static int nextID;

int age;
bool alive;

//location
double x;
double y;
double z;

animal()
{
age = 0;
id = 0;
alive = 1;
x = 0;
y = 0;
z = 0;
id = ++nextID;
}

animal(int age, double x, double y)
{
this->age = age;
this->x = x;
this->y = y;
z = 0;
id = ++nextID;
}

virtual void move(double x, double y)
{
this->x = x;
this->y = y;
}

animal(const animal &a)
{
age = a.age;
id = a.id;
alive = a.alive;
x = a.x;
y = a.y;
z = 0;
}

virtual void sleep()
{
cout<<"Animal "<<id<<" is Sleeping.\n";
}

virtual void eat()
{
cout<<"Animal "<<id<<" is Eating.\n";
}

void setAlive(bool alive)
{
this->alive = alive;
}

friend ostream & operator << (ostream &out, const animal &a);
virtual ~animal()
{}
};
ostream &operator << (ostream &out, const animal &a)
{
out<<"ID: "<<a.id<<endl;
out<<"Age: "<<a.age<<endl;
out<<"Alive: ";
if(a.alive == 1)
out<<"Yes"<<endl;
else
out<<"No"<<endl;
out<<"Coordinates: "<<a.x<<" "<<a.y<<" "<<a.z<<endl;
out<<endl;
return out;
}
class bird : public animal
{
public:
bird()
{
age = 0;
x = 0;
y = 0;
z = 0;
}

bird(int age, double x, double y, double z)
{
this->age = age;
this->x = x;
this->y = y;
this->z = z;
}

void move(double x, double y, double z)
{
this->x = x;
this->y = y;
this->z = z;
}

bird(const bird &b)
{
age = b.age;
id = b.id;
alive = b.alive;
x = b.x;
y = b.y;
z = b.z;
}

virtual ~bird(){}

virtual void sleep()
{
cout<<"Bird "<<id<<" is Sleeping.\n";
}

virtual void eat()
{
cout<<"Bird "<<id<<" is Eating.\n";
}

friend ostream & operator << (ostream &out, const bird &b);
};
ostream &operator << (ostream &out, const bird &b)
{
out<<"ID: "<<b.id<<endl;
out<<"Age: "<<b.age<<endl;
out<<"Alive: ";
if(b.alive == 1)
out<<"Yes"<<endl;
else
out<<"No"<<endl;
out<<"Coordinates: "<<b.x<<" "<<b.y<<" "<<b.z<<endl;
out<<endl;
return out;
}
class canine : public animal
{
public:
canine()
{
age = 0;
x = 0;
y = 0;
}

canine(int age, double x, double y)
{
this->age = age;
this->x = x;
this->y = y;
}

void move(double x, double y)
{
this->x = x;
this->y = y;
}

canine(const canine &c)
{
age = c.age;
id = c.id;
alive = c.alive;
x = c.x;
y = c.y;
}

virtual ~canine(){}

virtual void sleep()
{
cout<<"Canine "<<id <<" is Sleeping.\n";
}

virtual void eat()
{
cout<<"Canine "<<id <<" is Eating.\n";
}

void hunt(animal *a)
{
double d1, d2, d3;
d1 = abs(a->x - x);
d2 = abs(a->y - y);
d3 = abs(a->z - z);

if(d1<=1 && d2<=1 && d3<=1)
{
a->setAlive(0);
cout<<"Hunt Successful\n";
}
else
{
cout<<"Hunt Unsuccessful\n";
}
}

friend ostream & operator << (ostream &out, const canine &c);
};
ostream &operator << (ostream &out, const canine &c)
{
out<<"ID: "<<c.id<<endl;
out<<"Age: "<<c.age<<endl;
out<<"Alive: ";
if(c.alive == 1)
out<<"Yes"<<endl;
else
out<<"No"<<endl;
out<<"Coordinates: "<<c.x<<" "<<c.y<<" "<<c.z<<endl;
out<<endl;
return out;
}
//unique id starting from 101
int animal::nextID = 100;
int main()
{
//Testing different methods of classes above
animal a(5, 55.2, 33.5);
cout<<a;

bird b(10, 30, 15, 20);
cout<<b;

canine c(15, 2, 60);
cout<<c;

a.move(20, 50);
c.move(21, 49);

cout<<a<<c;

a.eat();
b.sleep();
c.sleep();

cout<<"\n";
animal *ani;
ani = &a;
c.hunt(ani);
return 0;
}
