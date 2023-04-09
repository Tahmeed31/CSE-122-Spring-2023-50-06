#include <iostream>
#include <string>
using namespace std;
class publication{
private:
    string title;
    float price;
public:
    void getData(){
    cout<<"Enter the title: ";
    cin>>title;
    cout<<"Enter the price:";
    cin>>price;
    }

    void putData(){
    cout<<"The title is:"<<title<<endl;
    cout<<"The price is: $"<<price<<endl;
    }
};
class book: public publication{
private:
    int page_number;
public:
    void getData(){
        publication::getData();
    cout<<"Enter the total pages:";
    cin>>page_number;
    }
    void putData(){
    publication::putData();
    cout<<"Total page number:"<<page_number<<endl;
    }
};
class tape: public publication{
private:
    float play_time;
public:
    void getData(){
    publication::getData();
    cout<<"Enter the playing time: ";
    cin>>play_time;
    }
    void putData(){
    publication::putData();
    cout<<"The playing time is:"<<play_time<<"minutes"<<endl;
    }
};

int main(){
book a;
tape b;

cout<<"Enter the information for the book:"<<endl;
a.getData();
cout<<endl;

cout<<"Enter the information for the tape:"<<endl;
b.getData();
cout<<endl;

cout<<"Info of Book:"<<endl;
a.putData();
cout<<endl;

cout<<"Info of Tape:"<<endl;
b.putData();
cout<<endl;
return 0;
}
