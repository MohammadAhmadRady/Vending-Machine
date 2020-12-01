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

item::item(){}
item::~item(){}
item::item(string n,int p,int avail,string t )
{
    name=n;
    price=p;
    ID=rand()%700;
    avail_amount=avail;
    type=t;
}

//int item::avail_amount=20;

void item::set_name(string n)
{
    name=n;
}
void item::set_price(int p)
{
    price=p;
}
void item::set_id()
{
    ID=rand()%700;
}
void item::set_avail(int a)
{
    avail_amount=a;
}
void item::set_type(string t)
{
    type=t;
}
string item::get_name()
{
    return name;
}
string item::get_type()
{
    return type;
}
int item::get_avail()
{
    return avail_amount;
}
int item::get_id()
{
    return ID;
}
int item::get_price()
{
    return price;
}
