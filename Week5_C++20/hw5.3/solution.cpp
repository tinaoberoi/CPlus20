#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <shared_mutex>

using namespace std;

class Stack
{
public:
    Stack(){};
    list<int> stack;
    shared_mutex mutable mtx;
    
    void push(int elem)
    {
        unique_lock lock(mtx);
        cout << "Element Pushed to Stack : " << elem << endl;
        stack.push_front(elem);
    }

    void pop()
    {
        unique_lock lock(mtx);
        cout << "popped: " << stack.front() << endl;
        stack.pop_front();
    }

};

int main()
{
    Stack *st = new Stack();

    jthread t1(&Stack::push, std::ref(st), 78);
    jthread t2(&Stack::push, std::ref(st), 8);
    jthread t3(&Stack::push, std::ref(st), 18);
    jthread t4(&Stack::push, std::ref(st), 10);
    jthread t5(&Stack::pop, st);

    st->push(-1);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    delete st;
    return 0;
}
