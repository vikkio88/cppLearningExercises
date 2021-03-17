#include <iostream>

using std::cin;
using std::cout;
using std::string;

void getInput(string label, string *str)
{
    cout << label << ":";
    cin >> *str;
}

void getInput(string label, int *val)
{
    cout << label << ":";
    cin >> *val;
}

string reverseString(string str)
{
    string reversed = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversed += str[i];
    }

    return reversed;
}

int main()
{
    string name = "";
    int age = 0;

    getInput("Name", &name);
    getInput("Age", &age);

    cout << "- " << name << " (" << age << ")" << std::endl;

    cout << std::endl;

    string reversed = reverseString(name);

    bool isPalindrome = name == reversed;

    cout << (isPalindrome ? "Palindrome" : ("Not Palindrome (" + reversed + ")")) << std::endl;
}
