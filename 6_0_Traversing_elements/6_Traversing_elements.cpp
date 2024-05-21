#include <iostream>
#include <fstream>
#include <chrono>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <forward_list>
using namespace std;

double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
};


int main()
{
    ifstream input;
    ofstream out, out1, out2, out3, out4, out5, out6, out7, out8, out9;
    input.open("Data5mil.txt");
    //out.open("Vector_Bypass_Time.txt");
    //out1.open("Vector_Bypass_size.txt");
    //out2.open("List_Bypass_time.txt");
    //out3.open("List_Bypass_size.txt");
    //out4.open("ForwardList_Bypass_time.txt");
    //out5.open("ForwardList_Bypass_size.txt");
    //out6.open("MultiSet_Bypass_time.txt");
    //out7.open("MultiSet_Bypass_size.txt");
    out8.open("MultiMap_Bypass_time.txt");
    out9.open("MultiMap_Bypass_size.txt");
    int ch,ch1;
    double start,finish, time;
    time = 0;
    multimap <int,int> v;

    for (int i=0;i<100000;i++)
    {
        input >> ch >> ch1;
        v.insert({ch1,ch});
        start=get_time();
        for (multimap<int,int>::iterator it=v.begin(); it!=v.end(); ++it)
            {

            }
        finish=get_time();
        time=time+finish-start;
        if (i%1000==999)
        {
            out8 << time <<endl;
            out9 << v.size() << endl;
            time=0;
        }
    }
    //out.close();
    //out1.close();
    //out2.close();
    //out3.close();
    //out4.close();
    //out5.close();
    out8.close();
    out9.close();
    input.close();
}
