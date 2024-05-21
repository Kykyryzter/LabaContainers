#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <forward_list>
using namespace std;

double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}

int main()
{
    ifstream input;
    ofstream out, out1;
    input.open("Data5mil.txt");
    out.open("ForwardList_Push_Front_Time.txt");
    out1.open("ForwardList_Push_Front_Size.txt");
    int ch;
    double start,finish;
    forward_list <int> v;

    for (int i=0; i<5000000; i++)
    {
        input >> ch;
        if (i%50000==0)
            start = get_time();
        v.push_front(ch);
        if (i%50000==49999)
        {finish = get_time();
        out << finish-start << endl;
        out1 << i+1 << endl;}
    }
    out.close();
    out1.close();
    input.close();
}
