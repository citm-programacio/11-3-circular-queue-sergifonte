#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int _front;
    int _back;
    int* _array;
    int _capacity;
    int _size;


    void resize()
    {
        int newCapacity = _capacity * 2;
        int* newArray = new int[newCapacity];


        int index = _front;
        for (int i = 0; i < _size; ++i)
        {
            newArray[i] = _array[index];
            index++;
            if (index == _capacity)
            {
                index = 0;
            }
        }


        delete[] _array;
        _array = newArray;
        _capacity = newCapacity;
        _front = 0;
        _back = _size - 1;
    }

public:
    CircularQueue(int capacity = 10) 
    {
        _capacity = capacity;
        _array = new int[_capacity];
        _front = -1;
        _back = -1;
        _size = 0;
    }

    ~CircularQueue() 
    {
        delete[] _array;
    }

    void enqueue(int value)
    {
        if (_size == _capacity)
        {
            resize();
        }

        if (_front == -1)
        {
            _front = 0;
        }

        _back++;
        if (_back == _capacity)
        {
            _back = 0;
        }

        _array[_back] = value;
        _size++;
    }

    int dequeue()
    {
        if (_size == 0)
        {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return -1;
        }

        int value = _array[_front];

        _front++;
        if (_front == _capacity)
        {
            _front = 0;
        }

        _size--;

        if (_size == 0)
        {
            _front = -1;
            _back = -1;
        }

        return value;
    }


    int size() const 
    {
        return _size;
    }

    bool empty() const 
    {
        return _size == 0;
    }

    void print() const 
    {
        if (empty()) 
        {
            cout << "Queue is empty. Nothing to print.\n";
            return;
        }

        cout << "Queue elements: ";
        int index = _front;
        for (int i = 0; i < _size; ++i) 
        {
            cout << _array[index] << " ";
            index++;
            if (index == _capacity) 
            {
                index = 0;
            }
        }
        cout << endl;
    }
};

int main() 
{
    CircularQueue queue1(3);

    queue1.enqueue(10);
    queue1.enqueue(20);
    queue1.enqueue(30);
    queue1.print();

    queue1.enqueue(40);
    queue1.print();

    queue1.dequeue();
    queue1.enqueue(50);
    queue1.print();
}