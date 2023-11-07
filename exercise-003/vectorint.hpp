#ifndef MY_INTEGER_VECTOR_HPP
#define MY_INTEGER_VECTOR_HPP

class VectorInt {
public:
    VectorInt(int size);
    ~VectorInt();
    void push_back(int data);
    int at(int pos);
    int size();
    int max_size();
    void resize(int new_size);
    void clear(int pos);
private:
    int m_size;
    int capacity;
    int* mp_Data;
};

#endif