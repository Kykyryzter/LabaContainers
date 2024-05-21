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
    input1.open("Data.txt");
    input2.open("Insert.txt");
    out.open("Vector_RandomInsert_Time.txt");
    out1.open("Vector_RandomInsert_Size.txt");
    //out2.open("MyVector_RandomInsert.txt");
    int ch,ins;
    double start,finish;
    vector <int> v;

    for (int i=0; i<100000; i++)
    {
        input1 >> ch;
        input2 >> ins;
        if (i%1000==0)
            start = get_time();
        v.insert(v.begin()+ins,ch);
        if (i%1000==999)
        {finish = get_time();
        out << finish-start << endl;
        out1 << v.size() << endl;}
        //out2 << pop_capacity(&Vector) << endl;
    }
    out.close();
    out1.close();
    out2.close();
    input1.close();
    input2.close();
}
