#include <iostream>

int main()
{
    int sum = 0, n = 1;
    int count = 0;
    std::cout << "Enter a list of numbers terminted by a non numeric character: " << std::endl;

    while (std::cin >> n)
    {
        sum += n;
        count++;
    }

    std::cout << "Count of entered numbers is " << count << " and the Total is " << sum << std::endl;
    std::cout << "Average of entered numbers is " << sum / (double)count << std::endl;

    std::cin.ignore();
    return 0;
}