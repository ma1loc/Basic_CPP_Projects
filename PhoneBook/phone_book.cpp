#include <iostream>

using std::cout;
using std::endl;

// {1,3,5,7,9}

int secondMinimum(int arr[], int size)
{
    int secondmin = 2147483647;
    int min = 2147483647;
  
    int i = 0;
    while (i < size)
    {
        if (arr[i] < min)
        {
            secondmin = min;
            min = arr[i];
        }
        if (arr[i] < secondmin && min != arr[i])
            secondmin = arr[i];
        i++;
    }  
  return secondmin;
}
int main()
{
    int arry[] = {3,5,7, 2, 9};
    int sizeofarry = sizeof(arry) / sizeof(arry[0]);

    cout << secondMinimum(arry, sizeofarry);

    return (0);
}