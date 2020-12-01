#ifndef ITEM_H
#define ITEM_H

using namespace std;

class item
{
    private:
        string name;
        int price;
        int ID;
        int avail_amount;
        string type;
    public:
        item();
        ~item();
        item(string n,int p,int avail,string t );
        void set_name(string n);
        void set_price(int p);
        void set_id();
        void set_avail(int a);
        void set_type(string t);
        string get_name();
        string get_type();
        int get_avail();
        int get_id();
        int get_price();
};

#endif // ITEM_H
