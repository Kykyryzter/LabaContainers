#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
using namespace std;

struct subvector {
     int *mas;
     unsigned int top;
     unsigned int capacity;
};

int rand_uns(int min, int max)
{
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        static std::default_random_engine e(seed);
        std::uniform_int_distribution<int> d(min, max);
        return d(e);
}

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

bool erase(subvector *qv, int b)
{
    if(qv->top == 0)
        return 1;
    int *a=new int[qv->top-1];
    int i=0;
    while (i<b)
    {
        a[i]=(qv->mas)[i];
        i++;
    }
    if (qv->top-i-1==0)
        {
            delete[] qv->mas;
            qv->mas = a;
            qv->capacity++;
            qv->top++;
            return 1;
        }

    while (i<qv->top)
    {
        a[i]=(qv->mas)[i+1];
        i++;
        if ((qv->mas)[i+1]==NULL)
            break;
    }
    delete[] qv->mas;
    qv->mas = a;
    delete[] a;
    qv->capacity--;
    qv->top--;
    return 1;
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
    subvector Vector, Oleg;
    init(&Oleg);
    init(&Vector);
    ifstream input1;
    ofstream out, out1, out2;
    input1.open("Data.txt");
    out.open("MyVector_Erase_Time.txt");
    out1.open("MyVector_Erase_Size.txt");
    //out2.open("MyVector_RandomInsert.txt");
    int ch,ins,aleg;
    double start,finish;

    for (int i=0;i<100000; i++)
        {input1 >> ins;
        push_back(&Vector,ins);}

    for (int i=0; i<100000; i++)
    {
        if (i%1000==0)
            start = get_time();
        erase(&Vector,rand()%pop_top(&Vector));
        if (i%1000==999)
        {finish = get_time();
        out << finish-start << endl;
        out1 << pop_top(&Vector) << endl;}
        //out2 << pop_capacity(&Vector) << endl;
    }
    out.close();
    out1.close();
    out2.close();
    input1.close();
}
