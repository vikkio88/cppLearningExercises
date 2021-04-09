#include <iostream>
#include <sstream>
#include <algorithm>

bool isPalindrome(int number)
{
    std::stringstream ss;
    ss << number;
    std::string num = ss.str();
    std::string reversed = ss.str();
    std::reverse(reversed.begin(), reversed.end());
    return reversed == num;
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