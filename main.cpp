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

int main()
{
    stock val;
    val.taking();
    admin administrator("Administrator","General");
    return 0;
}
