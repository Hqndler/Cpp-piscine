#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{

    private:

    public:
        Intern(void);
        ~Intern(void);
        Intern(const Intern &i);
        Intern &operator=(const Intern &i);

        AForm *make_form(const std::string &name, const std::string &target) const;
        AForm *make_pp(const std::string &target) const;
        AForm *make_rr(const std::string &target) const;
        AForm *make_sc(const std::string &target) const;

};

#endif