# include <iostream>
#include <vector>
#include "Account_copy.hpp"
# include <utility>

//  ----------------- about the apple ------------------- //
class Apple
{
    // access sp
    private:
        std::string color;
        double      weight;
        bool        isRipe;
    public:
        std::string getColor();
        double      getWeight();
        bool        getRipen();
        void        printInfo();
        Apple(std::string color, double weight, bool isRipe);
};

std::string Apple::getColor()
{
    return (color);
}

double Apple::getWeight()
{
    return (weight);
}

bool Apple::getRipen()
{
    return (isRipe);
}

class AppleBasket
{
    private:
        std::vector<Apple> apples;
    public:
        void    addApple(const Apple &a);   // refrance of the object
        void    showAllApples();
        int     countRipeApples();
};

void    AppleBasket::addApple(const Apple &a)
{
    apples.push_back(a);
}

void    AppleBasket::showAllApples()
{ 
    for (size_t i = 0; i < apples.size(); i++)
    {
        std::cout << "apple: " << i + 1
                << " color: " << apples.at(i).getColor()
                << " weight: " << apples.at(i).getWeight()
                << " is Ripe: " << apples.at(i).getRipen()
                << std::endl;
    }
}

int    AppleBasket::countRipeApples()
{

    int counter;

    counter = 0;

    for (size_t i = 0; i < apples.size(); i++)
    {
        if (apples.at(i).getRipen() == true)
            counter++;
    }
    return (counter);
}

Apple::Apple(std::string color, double weight, bool isRipe)
{
    this->color = color;
    this->weight = weight;
    this->isRipe = isRipe;
}

int main()
{
    // std::vector<Apple> apples;
    
    AppleBasket apples;

    Apple apple1("red", 10, false);
    Apple apple2("red", 20, false);
    Apple apple3("red", 30, false);

    apples.addApple(apple1);
    apples.addApple(apple2);
    apples.addApple(apple3);
    
}
