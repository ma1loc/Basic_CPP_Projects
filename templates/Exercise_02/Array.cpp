# include <iostream>
# include "Array.hpp"
# include "Array.tpp"

# define TOTAL_STUDENT 5

void    Array_with_string()
{
    Array<std::string> Student_info(TOTAL_STUDENT);
    std::string *student_names = new std::string[TOTAL_STUDENT];
    std::string names[] = {"youness", "ahmed", "yassine", "othmane", "karim"};
    
    std::cout << "\n========== set the ides to every student ==========" << std::endl;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        student_names[i] = "Student_" + names[i];

    std::cout << "\n========== value of Student_info object class before ==========" << std::endl;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        std::cout << "Student_info ---> " << Student_info[i] << std::endl;
    
    std::cout << "\n========== call the assingment operatorator to set Student_info ==========" << std::endl;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        Student_info[i] = student_names[i];

    std::cout << "\n========== value of Student_info object class after ==========" << std::endl;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        std::cout << "Student_info ---> " << Student_info[i] << std::endl;

    std::cout << "\n========== out_of_range index exceptions ==========" << std::endl;
    try
    {
        Student_info[1] = "Unkonwn_Student";
        for (int i = 0; i < TOTAL_STUDENT; i++)
            std::cout << "Student_info ---> " << Student_info[i] << std::endl;
        
        Student_info[-100] = "Unkonwn_Student";
    }
    catch (std::exception &e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== test the copy assigment ==========" << std::endl;
    Array<std::string> tmp = Student_info;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        std::cout << "tmp => Student_info ---> " << tmp[i] << std::endl;

    std::cout << "\n========== change the original student_info ==========" << std::endl;
    Student_info[1] = "Student_22 'get value back'";
    for (int i = 0; i < TOTAL_STUDENT; i++)
            std::cout << "Student_info ---> " << Student_info[i] << std::endl;

    std::cout << "\n========== check tmp student info after changing Original infos ==========" << std::endl;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        std::cout << "tmp => Student_info ---> " << tmp[i] << std::endl;
    
    delete[] student_names;
}

void    Array_with_numbers()
{
    Array<int> Student_info(TOTAL_STUDENT);
    int *student_age = new int[TOTAL_STUDENT];
    int age[] = {25, 22, 20, 21, 19};

    
    std::cout << "\n========== set age to every student ==========" << std::endl;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        student_age[i] = age[i];

    std::cout << "\n========== value of Student_info object class before ==========" << std::endl;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        std::cout << "Student_info ---> " << Student_info[i] << std::endl;
    
    std::cout << "\n========== call the assingment operatorator to set Student_info ==========" << std::endl;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        Student_info[i] = student_age[i];

    std::cout << "\n========== value of Student_info object class after ==========" << std::endl;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        std::cout << "Student_info ---> " << Student_info[i] << std::endl;

    std::cout << "\n========== out_of_range index exceptions ==========" << std::endl;
    try
    {
        Student_info[1] = 0;
        for (int i = 0; i < TOTAL_STUDENT; i++)
            std::cout << "Student_info ---> " << Student_info[i] << std::endl;
        
        Student_info[-100] = 0;
    }
    catch (std::exception &e)
    {
        std::cout << "exception: " << e.what() << std::endl;
    }

    std::cout << "\n========== test the copy assigment ==========" << std::endl;
    Array<int> tmp = Student_info;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        std::cout << "tmp => Student_info ---> " << tmp[i] << std::endl;

    std::cout << "\n========== change the original student_info ==========" << std::endl;
    Student_info[1] = 22;
    for (int i = 0; i < TOTAL_STUDENT; i++)
            std::cout << "Student_info ---> " << Student_info[i] << std::endl;

    std::cout << "\n========== check tmp student info after changing Original infos ==========" << std::endl;
    for (int i = 0; i < TOTAL_STUDENT; i++)
        std::cout << "tmp => Student_info ---> " << tmp[i] << std::endl;
    
    delete[] student_age;
}
