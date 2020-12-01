#ifndef ADMIN_H
#define ADMIN_H

class admin : public person
{
    public:
        void report_available_item();
        void add_new_item();
        void update_existing_item();
        void report_total_revenue();
        void total_customer();
        void max_receipt();
        admin();
        admin(string,string);
        ~admin();
        void loadstock();
};

#endif // ADMIN_H
