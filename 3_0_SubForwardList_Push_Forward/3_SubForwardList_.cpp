#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;


struct subforwardlist {

    int data;

    subforwardlist* next;

};

double get_time()
{
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
}

bool init(subforwardlist **sfl)
{
    *sfl = NULL;
    return 1;
}//инициализация пустого недосписка
bool push_back(subforwardlist **sfl, int d)
{
    if (*sfl == NULL) {
        subforwardlist* n = new subforwardlist;
        n->data = d;
        n->next = NULL;
        *sfl = n;
    }
    else {
        subforwardlist* n = *sfl;
        while (n->next != NULL) {
            n=n->next;
        }
        subforwardlist* m = new subforwardlist;
        m->data = d;
        m->next = NULL;
        n->next = m;
    }
    return 1;
}
int pop_back(subforwardlist **sfl)
{
    if (*sfl == NULL) {
        return 0;
    }
    else {
        if ((*sfl)->next == NULL) {
            int a = (*sfl)->data;
            delete *sfl;
            (*sfl) = NULL;
            return a;
        }
        else {
            subforwardlist* n = *sfl;
            while (n->next->next!=NULL) {
                n = n->next;
            }
            int a = n->next->data;
            delete n->next;
            n->next = NULL;
            return a;
        }
    }
}//удаление элемента с конца недосписка, если пустой - возвращать 0
bool push_forward(subforwardlist **sfl, int d)
{
    subforwardlist* n = new subforwardlist;
    n->data = d;
    n->next = *sfl;
    *sfl = n;
    return 1;
}//добавление элемента в начало недосписка
int pop_forward(subforwardlist  **sfl)
{
    if (*sfl == NULL) {
        return 0;
    }
    else {
        subforwardlist* n = (*sfl)->next;
        int a = (*sfl)->data;
        delete *sfl;
        *sfl = n;
        return a;
    }

}//удаление элемента из начала недосписка, если пустой - возвращать 0
bool push_where(subforwardlist **sfl, unsigned int where, int d)
{
    subforwardlist* n = *sfl;
    for (unsigned int i = 0; i < where; i++) {
        n = n->next;
    }
    subforwardlist* m = new subforwardlist;
    m->next = n->next;
    m->data = d;
    n->next = m;
    return 1;
}//добавление элемента с порядковым номером where
int erase_where(subforwardlist **sfl, unsigned int where)
{
    int a = 0;
    subforwardlist *n = *sfl;
    for (unsigned int i = 0; i < where; i++) {
        n = n->next;
    }
    subforwardlist* m = n->next->next;
    a = n->next->data;
    delete n->next;
    n->next = m;
    return a;
}//удаление элемента с порядковым номером where, если пустой - возвращать 0
unsigned int size(subforwardlist  **sfl)
{
    unsigned int a = 1;
    if (*sfl == NULL)
        return 0;
    subforwardlist* n = *sfl;
    while (n->next != NULL) {
        n = n->next;
        a++;
    }
    return a;

}//определить размер недосписка
void clear(subforwardlist  **sfl)
{
    while ((*sfl)!=NULL)
        pop_back(sfl);
}

int main()
{
    subforwardlist* List;
    init(&List);
    ifstream input;
    ofstream out, out1;
    input.open("Data5mil.txt");
    out.open("SubForwardList_Time.txt");
    out1.open("SubForwardList_Size.txt");
    int ch;
    double start,finish;

    for (int i=0; i<5000000; i++)
    {
        input >> ch;
        if (i%50000==0)
            start = get_time();
        push_forward(&List,ch);
        if (i%50000==49999)
        {finish = get_time();
        out << finish-start << endl;
        out1 << size(&List) << endl;}
        //out2 << pop_capacity(&Vector) << endl;
    }
    out.close();
    out1.close();
    input.close();
}
