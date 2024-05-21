#include <iostream>
#include <fstream>
#include <random>
using namespace std;


int main()
{
    std::ofstream out;
    out.open("Insert.txt");
    if (out.is_open())
    {
        for (int i=0;i<100000;i++)
        out << rand() % (i+1) << std::endl;
    }
    out.close();
    std::cout << "File has been written" << std::endl;
}
