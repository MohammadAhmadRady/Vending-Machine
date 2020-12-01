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
stock::stock(){}

void stock::taking()
{
    fstream load("Loadstock.txt",ios::in);
    for (int i=0;i<5;i++)
    {
        string name,type;
        int price,amount;
        load>>name>>price>>amount>>type;
        stock::list_of_item[i].set_name(name);
        stock::list_of_item[i].set_price(price);
        stock::list_of_item[i].set_avail(amount);
        stock::list_of_item[i].set_type(type);
    }
}

stock::~stock(){}

int stock::n=100;
int stock::n1=4;
item* stock::list_of_item=new item[n];
