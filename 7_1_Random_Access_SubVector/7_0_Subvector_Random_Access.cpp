#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <vector>
using namespace std;

struct subvector {
     int *mas;
     unsigned int top;
     unsigned int capacity;
};

double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}

unsigned int pop_capacity(subvector *qv)
{
    return (qv->capacity);
}

unsigned int pop_top(subvector *qv)
{
    return (qv->top);
}

bool init(subvector *qv)
{
    qv->capacity=0;
    qv->top=0;
    qv->mas=NULL;
    return 1;
}

int random_access(subvector *qv, unsigned int position)
{
    (qv->mas)[position]++;
    return (qv->mas)[position];
}

bool resize(subvector *qv,unsigned int new_capacity)
{
    if (new_capacity < qv->top){
        qv->top = new_capacity;
    }
    int *a=new int[new_capacity];
    for (unsigned int i=0;i<qv->top;i++)
        a[i]=(qv->mas)[i];
    delete [] qv->mas;
    qv->capacity=new_capacity;
    qv->mas = a;
    return 1;
}
bool push_back(subvector *qv, int d)
{
    if (qv->top==qv->capacity)
        resize(qv,qv->top+1);
    qv->mas[qv->top]=d;
    qv->top++;
    return 1;
}

int pop_back(subvector *qv)
{
    if (qv->top==0)
        return 0;
    int a=qv->mas[qv->top-1];
    qv->top--;
    return a;
}

void shrink_to_fit(subvector *qv)
{
    if (qv->capacity > qv->top){
    int *b=new int[qv->top];
    for (unsigned int i=0;i<qv->top;i++)
        b[i]=(qv->mas)[i];
    delete[] qv->mas;
    qv->capacity=qv->top;
    qv->mas=b;}
}

void clear(subvector *qv)
{
    qv->top=0;
}

void destructor(subvector *qv)
{
    delete [] qv->mas;
    qv->mas=NULL;
    qv->capacity=0;
    qv->top=0;
}

int main()
{
    subvector Vector;
    init(&Vector);
    ifstream input("Data5mil.txt");
    ifstream input1("Random_access.txt");
    ofstream out, out1;
    out.open("SubVector_time.txt");
    out1.open("SubVector_size.txt");
    int ch;
    unsigned int ch1;
    double start, finish, time;

    for (int i=0; i<400000; i++)
    {
        input >> ch;
        input1 >> ch1;
        push_back(&Vector,ch);
        start=get_time();
        random_access(&Vector,ch1);
        finish=get_time();
        time=time+finish-start;
        if (i%4000==3999)
        {
            out << time << endl;
            out1<< pop_top(&Vector)<<endl;
            time=0;
        }

    }
    out.close();
    out1.close();
    input.close();
    input1.close();
}
