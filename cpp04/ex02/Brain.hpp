#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{

    protected:
        std::string ideas[100];

    public:
        Brain(void);
        ~Brain(void);
        Brain(const Brain &b);
        Brain &operator=(const Brain &b);

        void set_idea(const std::string idea);
        void thinking(void) const;

};

#endif