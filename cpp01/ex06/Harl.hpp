#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl{

    private:
        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);

    public:
        void complain(std::string level);
        Harl(void);
        ~Harl(void);

};

#endif