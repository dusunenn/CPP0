#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << std::endl;
        return 1;
    }
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            std::string input = argv[i];
            for (size_t j = 0; j < input.length(); j++)
            {
                input[j] = std::toupper(input[j]);
            }
            std::cout << input;
        }
        std::cout << std::endl;
    }
    return 0;
}
