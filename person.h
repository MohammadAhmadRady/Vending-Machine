#ifndef PERSON_H
#define PERSON_H

class person
{
    private:
        string name;
        string address;
    public:
        person();
        ~person();
        person(string n ,string a);
        void set_name(string n);
        void set_address(string a);
        string get_name();
        string get_address();
};

#endif // PERSON_H
