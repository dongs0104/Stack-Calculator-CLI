#include <stdexcept>
#include <algorithm>
using namespace std;

template <class T>
class Stack
{ //0개 이상의 원소를 가진 유한 순서 리스트.
private:
    T* stack;
    int key; // Top key
    int capacity;// Stack array size
    
    
public:
    
    //constructor
    Stack(int capacity = 10);
    
    //member method
    bool isEmpty() const;
    //return top element
    T& top() const;
    //insert item Stack on top
    void push(const T& item);
    //delete item Top of Stack
    void pop();
    
};
template <class T>

void changeSize1D(T*& a,const int oldSize ,const int newSize);

template <class T>
Stack<T>::Stack(int capa):capacity(capa)
{
    if (capacity < 1) 
        throw std::runtime_error("Stack cacpcity must be > 0") ;
    stack = new T[capacity];
    key = -1;
}
template <class T>
void changeSize1D(T*& a,const int oldSize , const int newSize)
{
    if (newSize < 0 )throw std::runtime_error("New Length must be over 0") ;
    T* temp = new T [newSize];
    int num = min(oldSize, newSize);
    copy (a, a + num, temp);
    delete []a;
    a = temp;
}
template <class T>
bool Stack<T>::isEmpty() const {
    return (key == -1) ? true : false;
}
template <class T>
T& Stack<T>::top() const {
    if (isEmpty()) throw std::runtime_error( "This Stack is Empty" ) ;
    return stack[key];
}
template <class T>
void Stack<T>::push(const T& item) {
    if (key == capacity - 1)
    {
        changeSize1D(stack, capacity, capacity * 2);
        capacity = capacity * 2;
    }
    stack[++key] = item;
}
template <class T>
void Stack<T>::pop() {
    if(isEmpty())throw std::runtime_error( "Stackis Empty. Cannot delete." ) ;
    stack[key--].~T();
}

