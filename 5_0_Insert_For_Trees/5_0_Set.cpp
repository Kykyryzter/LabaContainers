#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <set>
#include <map>
using namespace std;

double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}

int main()
{
    ifstream input;
    ofstream out, out1, out2, out3, out4, out5, out6, out7;
    input.open("Data5mil.txt");
    //out.open("Set_insert_time.txt");
    //out1.open("Set_insert_size.txt");
    //out2.open("MultiSet_insert_time.txt");
    //out3.open("MultiSet_insert_size.txt");
    //out4.open("Map_insert_time.txt");
    //out5.open("Map_insert_size.txt");
    out6.open("MultiMap_insert_time.txt");
    out7.open("MultiMap_insert_size.txt");
    int ch,ch1;
    double start,finish;
    multimap <int,int> v;

    for (int i=0; i<5000000/2; i++)
    {
        input >> ch;
        input >>ch1;
        if (i%50000/2==0)
            start = get_time();
        v.insert({ch,ch1});
        if (i%50000/2==49999/2)
        {finish = get_time();
        out6 << finish-start << endl;
        out7 << v.size() << endl;}
    }
    //out.close();
    //out1.close();
    //out2.close();
    //out3.close();
    //out4.close();
    //out5.close();
    out6.close();
    out7.close();
    input.close();
}
