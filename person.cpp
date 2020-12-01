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

person::person()
{}

person::~person()
{}

person::person(string n,string a)
{
    name=n;
    address=a;
}
void person::set_name(string n)
{
    name=n;
}
void person::set_address(string a)
{
    address=a;
}
string person::get_address()
{
    return address;
}
string person::get_name()
{
    return name;
}
