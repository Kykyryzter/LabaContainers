#include <iostream>
#include <fstream>
#include <random>
using namespace std;


int main()
{
    std::ofstream out;
    out.open("Data.txt");
    if (out.is_open())
    {
        for (int i=0;i<100000;i++)
        out << rand() << std::endl;
    }
    out.close();
    std::cout << "File has been written" << std::endl;
}

