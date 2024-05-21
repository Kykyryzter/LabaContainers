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
} // инициализация пустого недовектора (top и capacity по нулям, а mas это NULL)

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
} // добавление элемента в конец недовектора с выделением дополнительной памяти при необходимости

int pop_back(subvector *qv)
{
    if (qv->top==0)
        return 0;
    int a=qv->mas[qv->top-1];
    qv->top--;
    return a;
} // удаление элемента с конца недовектора, значение удаленного элемента вернуть (если недовектор пустой, вернуть ноль)

void shrink_to_fit(subvector *qv)
{
    if (qv->capacity > qv->top){
    int *b=new int[qv->top];
    for (unsigned int i=0;i<qv->top;i++)
        b[i]=(qv->mas)[i];
    delete[] qv->mas;
    qv->capacity=qv->top;
    qv->mas=b;}
} // очистить неиспользуемую память, переехав на новое место с уменьшением capacity до top

void clear(subvector *qv)
{
    qv->top=0;
} // очистить содержимое недовектора, занимаемое место при этом не меняется

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
    int iteration=1;
    ifstream input("Data.txt");
    ofstream out, out1, out2;
    out.open("MyVectorIteration.txt");
    out1.open("MyVectorSize.txt");
    out2.open("MyVectorCapacity.txt");
    int ch;

    for (int i=0; i<100000; i++)
    {
        input >> ch;
        push_back(&Vector,ch);
        out << i << endl;
        out1 << pop_top(&Vector) << endl;
        out2 << pop_capacity(&Vector) << endl;
    }
    out.close();
    out1.close();
    out2.close();
    input.close();
}
