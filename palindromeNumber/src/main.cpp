#include <iostream>
#include <sstream>

bool isPalindrome(int number)
{
    std::stringstream ss;
    ss << number;
    std::string num, revNum;
    ss >> num;

    for (int i = num.length() - 1; i >= 0; i--)
    {
        revNum += num[i];
    }

    return revNum == num;
}

int main()
{
    const int numbs[] = {11, 22, 33, 45, 131, 456};
    int size = sizeof(numbs) / sizeof(numbs[0]);
    for (int i = 0; i < size; i++)
    {
        int num = numbs[i];

        std::cout << num << " " << (isPalindrome(num) ? "YES" : "NO") << std::endl;
    }
}