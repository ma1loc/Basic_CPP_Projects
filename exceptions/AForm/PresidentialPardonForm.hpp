# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class AForm;

class PresidentialPardonForm: public AForm	
{
	private:
		const std::string name;
		const int grade_signe;
		const int grade_execute;
		bool is_signed;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &_name, const int &_gradeSigne, const int &_gradeExecute, const bool _isSigned);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();

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

    class GradeSignException: public std::exception
    {
      public:
        const char *what() const throw();
    }
		void beSigned(const Bureaucrat &B);
};

#endif
