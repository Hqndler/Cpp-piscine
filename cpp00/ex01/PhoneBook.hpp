#ifndef PhoneBook_HPP
# define PhoneBook_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        static int  _index;
        Contact     _contact[8];

    public:
        void add_contact(void);
        void search(void) const;
        void show_all(void) const;
        void show_contact(Contact contact) const;
        PhoneBook(void);
        ~PhoneBook(void);

};

#endif