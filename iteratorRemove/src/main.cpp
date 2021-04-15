#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> sts = {"ciao", "hello", "yo", "sup", "halo", "yoyo"};

    auto it = sts.begin();
    while (it != sts.end())
    {
        if (*it == "yo")
        {
            it = sts.erase(it);
            continue;
        }

        it++;
    }

    for (auto &s : sts)
    {
        std::cout << '\t' << s << '\n';
    }

    return EXIT_SUCCESS;
}