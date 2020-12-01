#include <iostream>
#include <iomanip>
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

admin::admin()
{}

admin::admin(string n,string a)
{
    set_name(n);
    set_address(a);
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 ); //--black---
    int choice,value,customer_no,total_customer_no=0;
    string new_item,type,name;
    char val;
    admin admin1;
    customer *customers;
    while(true)
    {
        cout<<"Press 1 to Enter as Administrator, 2 to Enter as Customer, and 0 to End the program: ";
        cin>>choice;
        while (choice!=1 && choice!=2 && choice!=0)
        {
            cout<<"invalid choice please put a valid value ";
            cin>>choice;
        }
        if (choice==0)
        {

            loadstock();
            break;
        }
        else if (choice==1)
        {
            while(true)
            {
                cout<<"What you want to do: \n";
                cout<<"1-  ReportAvailableItems \n";
                cout<<"2-  AddNewItem \n";
                cout<<"3-  UpdateExistingItem \n";
                cout<<"4-  ReportTotalRevenue \n";
                cout<<"5-  DisplayTotalCustomers \n";
                cout<<"6-  DisplayMaxReceipt \n";
                cin>>value;
                while (value>6 || value<1)
                {
                    cout<<"invalid choice please enter a valid value: ";
                    cin>>value;
                }
                if (value==1) //ReportAvailableItems
                {
                    admin1.report_available_item();
                }
                else if (value==2) //AddNewItem
                {
                    admin1.add_new_item();
                }
                else if (value==3)
                {
                    admin1.update_existing_item(); //UpdateExistingItem
                }
                else if (value==4) //ReportTotalRevenue
                {
                    admin1.report_total_revenue();
                    for(int i=0; i<total_customer_no; i++)
                    {
                        cout<<"cut"<<i+1<<", checkout at ";
                        customers[i].checkout_time();
                    }
                    customer_no=0;
                    total_customer_no=0;
                }
                else if (value==5) //DisplayTotalCustomers
                {
                    admin1.total_customer();
                }
                else if (value==6) //DisplayMaxReceipt
                {
                    admin1.max_receipt();
                }
                cout<<"Do you want to do another operation? \n";
                cin>>val;
                while (val!='n' && val!='N' && val!='y' && val!='Y')
                {
                    cout<<"invalid Operation :: ";
                    cin>>val;
                }
                if (val=='n' || val=='N')
                {
                    break;
                }
            }
        }
        else if(choice==2)
        {
            cout<<"PLz enter number of customers: ";
            cin>>customer_no;
            total_customer_no+=customer_no;
            customers=new customer [customer_no];
            for(int i=0; i<customer_no; i++)
            {
                cout<<"PLz select from the following menu the items that Cut"<<i+1<<" bought:"<<endl;
                admin1.report_available_item();
                /*int choice;
                int amount;
                cout<<"choose the item : ";
                cin>>choice;
                while (stock::list_of_item[choice-1].get_avail() <= 0)
                {
                    cout<<"invalid choice: ";
                    cin>>choice;
                }
                while ( (choice - 1 > stock::n1)  || (choice<=0)    )
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
                cout<<"your amount equal : "<<amount<<endl;
                stock::list_of_item[choice-1].set_avail(stock::list_of_item[choice-1].get_avail()-amount);
                customer::receipt+=(stock::list_of_item[(choice-1)].get_price()*amount);
                if(((stock::list_of_item[(choice-1)].get_price()*amount)>customer::max_receipt))
                    customer::max_receipt=(stock::list_of_item[(choice-1)].get_price()*amount);
                cout<<"Receipt= "<<customer::receipt<<" LE"<<endl;
                customer::total_revenue+=customer::receipt;*/
                customers[i].buy_items();
            }
        }
    }
}

void admin::report_available_item() //1
{
    int counter=0;
    cout<<"Item \t|\t Type \t |   Units |   Price"<<endl;
    for(int i=0; i<=stock::n1; i++)
    {
        if (stock::list_of_item[i].get_avail()<=0)
        {
            counter++;
        }
        if (counter==stock::n1)
        {
            cout<<"empty!!\n";
            break;
        }
        if (stock::list_of_item[i].get_avail()<=0)
            continue;
        else if(stock::list_of_item[i].get_avail()<5)
        {
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x3C ); //---red---
            cout<<i+1<<"-"<<stock::list_of_item[i].get_name()<<setw(13)<<stock::list_of_item[i].get_type()<<"\t\t"<<stock::list_of_item[i].get_avail()<<"\t"<<stock::list_of_item[i].get_price()<<endl;
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 ); //--black---
        }
        else
            cout<<i+1<<"-"<<stock::list_of_item[i].get_name()<<setw(13)<<stock::list_of_item[i].get_type()<<"\t\t"<<stock::list_of_item[i].get_avail()<<"\t"<<stock::list_of_item[i].get_price()<<endl;
    }
}

void admin::add_new_item() //2
{
    stock::n1++;
    string name,type;
    int avamount;int price;
    cout<<"PLz enter the item name, type, available units, price:\n"<<endl;
    cout<<"Enter the name: ";
    cin>>name;
    cout<<"Enter the type: ";
    cout<<"From Washing, Drinking, Takeaway, Vegetables, and Meat: ";
    cin>>type;
    while (    type!="Washing" && type!="Drinking" && type!="Takeaway" && type!="Vegetables" && type!="Meat"
            && type!="washing" && type!="drinking" && type!="takeaway" && type!="vegetables" && type!="meat")
    {
        cout<<"invalid type: ";
        cin>>type;
    }
    cout<<"Enter the avail_amount: ";
    cin>>avamount;
    while (avamount<=0)
    {
        cout<<"invalid amount: ";
        cin>>avamount;
    }
    cout<<"Enter the price: ";
    cin>>price;
    while (price<=0)
    {
        cout<<"invalid price: ";
        cin>>price;
    }
    stock::list_of_item[stock::n1]=item(name,price,avamount,type);

}

void admin::update_existing_item() //3
{
    int n;
    cout<<"Please enter the number of item you want to update : ";
    cin>>n;
    int avail_mount_new,price_new;
    cout<<"PLz enter the item new available units, price:\n"<<endl;
    cout<<"Enter the new amount: ";
    cin>>avail_mount_new;
    while (avail_mount_new<=0)
    {
        cout<<"invalid amount; ";
        cin>>avail_mount_new;
    }
    cout<<"Enter the new price: ";
    cin>>price_new;
    while (price_new<=0)
    {
        cout<<"invalid price; ";
        cin>>price_new;
    }
    stock::list_of_item[(n-1)].set_avail(avail_mount_new);
    stock::list_of_item[(n-1)].set_price(price_new);
}

void admin::report_total_revenue() //4
{
    cout<<"Total Revenue = "<<customer::total_revenue<<" LE"<<endl;
    cout<<"Order of the customers are:"<<endl;
    customer::total_revenue=0;
    customer::id_customer=0;
}

void admin::total_customer() //5
{
    cout<<"The currently available customers are "<<customer::id_customer<<endl;
}

void admin::max_receipt() //6
{
    cout<<"Max Receipt Value = "<<customer::max_receipt<<endl;
}
void admin::loadstock()
{
    ofstream loading("file.txt", ios::out | ios::app);
    loading<<"\t\t\t\t There's the Items \n\n";
        for (int i=0;i<stock::n1+1;i++)
        {
            if (stock::list_of_item[i].get_avail()<=0)
                continue;
            loading<<i+1<<"- Name: "<<stock::list_of_item[i].get_name()<<endl;
            loading<<"Price: "<<stock::list_of_item[i].get_price()<<endl;
            loading<<"Available Amount: "<<stock::list_of_item[i].get_avail()<<endl;
            loading<<"Type: "<<stock::list_of_item[i].get_type()<<endl<<endl;
        }
}

admin::~admin(){}
