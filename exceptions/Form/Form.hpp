# ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>
//# include "Bureaucrat.hpp"

class Bureaucrat; // forward declaration

class Form
{
  private:
    const std::string name;
    const int grade_signe;
    const int grade_execute;
    bool is_signed;
  public:
    Form();
    Form(const Form &copy);
    Form &operator=(const Form &copy);
    ~Form();

    Form(const std::string &_name, const int &_gradeSigne, const int &_gradeExecute);

    const std::string &getName() const;
    const int &getGradeSigne() const;
    const int &getGradeExecute() const;
    bool getIsSigned() const;

    class GradeTooHighException: public std::exception
    {
      public:
        const char* what() const throw();
    };
    
    class GradeTooLowException: public std::exception
    {
      public:
        const char* what() const throw();
    };

    void beSigned(const Bureaucrat &B); // the new one //
};

std::ostream &operator<<(std::ostream &out, const Form &f);

# endif
