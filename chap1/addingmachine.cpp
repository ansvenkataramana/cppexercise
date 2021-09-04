#include <iostream>

int main()
{
    int sum = 0, n = 1;
    std::cout << "Enter a list of numbers terminted by a non numeric character: " << std::endl;

    while (std::cin >> n)
    {
        sum += n;
    }

    std::cout << "Total is " << sum << std::endl;

    std::cin.ignore();
    return 0;
}