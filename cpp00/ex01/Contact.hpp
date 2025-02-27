#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
    private:
        std::string _name;
        std::string _last_name;
        std::string _nickname;
        std::string _number;
        std::string _secret;

    public:
        std::string get_name(void) const;
        std::string get_last_name(void) const;
        std::string get_nickname(void) const;
        std::string get_number(void) const;
        std::string get_secret(void) const;

        void set_name(std::string str);
        void set_last_name(std::string str);
        void set_nickname(std::string str);
        void set_number(std::string str);
        void set_secret(std::string str);

        Contact(void);
        ~Contact(void);
};

#endif