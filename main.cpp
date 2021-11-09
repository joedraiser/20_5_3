#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream river("river.txt");
    if(!river.is_open())
    {
        std::cout << "river.txt is not opened";
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> fishTypes;

    std::string fishType;

    while(!river.eof())
    {
        river >> fishType;
        fishTypes.push_back(fishType);
    }

    river.close();

    std::cout << "Which kind of fish would you like to catch: ";
    std::cin >> fishType;

    std::fstream basket("basket.txt", std::ios::app);

    if(std::find(fishTypes.begin(), fishTypes.end(), fishType)!=fishTypes.end())
    {
        basket << fishType << std::endl;
    }

    basket.close();
    basket.open("basket.txt");

    std::cout << "Here is what you caught by now:\n";

    while(!basket.eof())
    {
        basket >> fishType;
        std::cout << fishType << std::endl;
    }

    basket.close();

    return 0;
}
