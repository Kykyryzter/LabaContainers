#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <vector>
using namespace std;

double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}

int main()
{
    ifstream input1, input2;
    ofstream out, out1, out2;
    input1.open("Data5mil.txt");
    input2.open("Random_access.txt");
    out.open("Vector_Random_access_Time.txt");
    out1.open("Vector_Random_access_Size.txt");
    int ch,ins;
    double start,finish,time;
    vector <int> v;

    for (int i=0; i<5000000; i++)
    {
        input1 >> ch;
        input2 >> ins;
        v.push_back(ch);
        start = get_time();
        v[ins]++;
        finish=get_time();
        time-finish-start;
        if (i%50000==49999)
        {
        out << time << endl;
        out1 << v.size() << endl;
        time=0;}
        //out2 << pop_capacity(&Vector) << endl;
    }
    out.close();
    out1.close();
    input1.close();
    input2.close();
}
