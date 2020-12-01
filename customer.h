#ifndef CUSTOMER_H
#define CUSTOMER_H

class customer : public person
{
    private:
        Time ArrivalTime,shoping_duration,checkout_times;
        int no_item[100];
        item items[100];
    public:
        static int receipt;
        static int id_customer;
        static int total_revenue;
        static int max_receipt;
        void checkout_time();
        void buy_items();
        int id();
        customer();
        customer(string,string);
        ~customer();
};

#endif // CUSTOMER_H
