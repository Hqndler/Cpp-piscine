#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shruberry Creation Form", 145, 137), _target("Nowhere"){
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shruberry Creation Form", 145, 137), _target(target){
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &p) : AForm(p), _target(p._target) {
    return;
}
ShrubberyCreationForm::~ShrubberyCreationForm(void){
    return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &p){
    (void)p;
    return *this;
}

const std::string ShrubberyCreationForm::get_target(void) const{
    return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
    execute_check(executor);
    // creation d'un fichier lul
    std::ofstream outfile((this->_target + "_shrubbery").c_str());
    if (!outfile.is_open()){
        std::cerr << "Couldn't create `" << this->_target << "_shrubbery`." << std::endl;
        return;
    }
    std::cout << this->_target << "_shruberry file created by " << executor.get_name() << "." << std::endl;

    outfile << "          &&& &&  & &&         " << std::endl;
    outfile << "      && &\\/&\\|& ()|/ @, &&  " << std::endl;
    outfile << "      &\\/(/&/&||/& /_/)_&/_&  " << std::endl;
    outfile << "   &() &\\/&|()|/&\\/ '%' & () " << std::endl;
    outfile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    outfile << "&&   && & &| &| /& & % ()& /&& " << std::endl;
    outfile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    outfile << "     &&     \\|||              " << std::endl;
    outfile << "             |||               " << std::endl;
    outfile << "             |||               " << std::endl;
    outfile << "             |||               " << std::endl;
    outfile << "       , -=-~  .-^- _          ";

    return;
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &p){
    o << "The target is " << p.get_name() << " for ";
   	o << "\"" << p.get_name() << "\" Shruberry Creation Form, require grade ";
	o << p.get_sign_grade() << " for signing it and grade ";
	o << p.get_exec_grade() << " for executing it. ";
	o << p.get_name();
	if (p.is_signed())
		o << " is signed.";
	else
		o << " isn't signed.";
	return o;
}