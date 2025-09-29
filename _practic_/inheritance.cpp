# include <iostream>

class Person
{
	private:
		std::string name;
		std::string age;
		std::string gender;

	public:

		Person()
		{
			std::cout << "person defule constractor called" << std::endl;
			name = "unknown";
			gender = "unknown";
			age = "0";
		}

		Person (std::string n, std::string a, std::string g)
		{
			std::cout << "person param constractor called" << std::endl;
			name = n;
			age = a;
			gender = g;
		}

		// Setters
		void setName(const std::string& newName) {
			name = newName;
		}

		void setAge(const std::string& newAge) {
			age = newAge;
		}

		void setGender(const std::string& newGender) {
			gender = newGender;
		}

		// Getters
		std::string getName() const {
			return name;
		}

		std::string getAge() const {
			return age;
		}

		std::string getGender() const {
			return gender;
		}

		void display()
		{
			std::cout << "name -> " << name << std::endl
					<< "age -> " << age << std::endl
					<< "gender -> " << gender << std::endl
					<< std::endl;
		}
};

class Student: public Person
{
	private:
		int level;
		std::string depart;
	public:
		Student() : Person("yoness", "25", "male")
		{
			std::cout << "studnet defulst constractor called" << std::endl;

			level = 0;
			depart = "Unkonwn";
		}
		
		Student(int l, std::string d): Person("youness", "23", "male")
		{
			std::cout << "student param constractor called" << std::endl;
			level = l;
			depart = d;
		}

		void set_level(int level)
		{
			this->level = level;
		}

		void set_depart(std::string depart)
		{
			this->depart = depart;
		}

		int	get_level()
		{
			return (level);
		}

		std::string get_depart()
		{
			return (depart);
		}

		void display()
		{
			std::cout << "overwrite seccessful" << std::endl;
			Person::display();
			std::cout << "level " << level << std::endl
					<< "depart " << depart << std::endl; 
		}
};

int	main()
{
	Student s1;
	Student s2(5, "CS");

	s1.display();
	s2.display();
}
