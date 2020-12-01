#include <iostream>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <windows.h>
#include "item.h"
#include "person.h"
#include "Time.h"
#include "stock.h"
#include "customer.h"
#include "admin.h"

using namespace std;

customer::customer()
{
    id_customer++;
    do
    {
        shoping_duration.set_hours(rand()%5);
    }
    while(shoping_duration.get_hours()<=0);
    shoping_duration.set_minutes(rand()%60);
}

customer::customer(string n,string a)
{
    set_name(n);
    set_address(a);
    id_customer++;
    do
    {
        shoping_duration.set_hours(rand()%5);
    }
    while(shoping_duration.get_hours()<=0);
    shoping_duration.set_minutes(rand()%60);
}

int customer::id()
{
    return id_customer;
}

void customer::checkout_time()
{
    int h,m;
    checkout_times=shoping_duration+ArrivalTime;
    if(checkout_times.get_minutes()>=60)
    {
        h=checkout_times.get_hours()+1;
        m=checkout_times.get_minutes()-60;
        checkout_times.set_hours(h);
        checkout_times.set_minutes(m);
    }
    cout<<checkout_times.get_hours()<<":"<<checkout_times.get_minutes()<<endl;
}

void customer::buy_items()
{
    int choice;
    int amount;
    cout<<"choose the item : ";
    cin>>choice;
    while (choice - 1 > stock::n1 || choice<=0 )
    {
        cout<<"invalid choice: ";
        cin>>choice;
    }
    cout<<"choose the amount : ";
    cin>>amount;
    while (stock::list_of_item[choice-1].get_avail() < amount || amount <=0)
    {
        cout<<"the amount is not enough : ";
        cin>>amount;
    }
    items[(id_customer-1)]=stock::list_of_item[(choice-1)];
    no_item[(id_customer-1)]=amount;
    cout<<"your amount equal : "<<amount<<endl;
    stock::list_of_item[choice-1].set_avail(stock::list_of_item[choice-1].get_avail()-amount);
    receipt+=(stock::list_of_item[(choice-1)].get_price()*amount);
    if(((stock::list_of_item[(choice-1)].get_price()*amount)>max_receipt))
        max_receipt=(stock::list_of_item[(choice-1)].get_price()*amount);
    cout<<"Receipt= "<<receipt<<" LE"<<endl;
    total_revenue+=receipt;
}
customer::~customer(){}

int customer::receipt=0;
int customer::id_customer=0;
int customer::total_revenue=0;
int customer::max_receipt=0;
