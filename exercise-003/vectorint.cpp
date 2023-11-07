#include "vectorint.hpp"

VectorInt::VectorInt(int size) {
    mp_Data = new int[size];
    m_size = 0;
    capacity = size;
}

VectorInt::~VectorInt() {
    if(mp_Data != nullptr) {
        delete [] mp_Data;
    }
    mp_Data = nullptr;
}

void VectorInt::push_back(int data){
    m_size++;
    if(m_size >= capacity){
       resize(m_size + 10); 
    };
    mp_Data[m_size - 1] = data;
};

int VectorInt::at(int pos){
    return mp_Data[pos];
};

int VectorInt::size(){
    return m_size;
};

int VectorInt::max_size(){
    return capacity;
};

void VectorInt::resize(int new_size){
    int* temp = new int[new_size];
    for(int i=0; i < capacity; i++){
        temp[i] = mp_Data[i];
    };
    capacity = new_size;
    delete [] mp_Data;
    mp_Data = temp;
};

void VectorInt::clear(int pos){
    for(int i = pos; i< m_size; i++){
        mp_Data[i] = 0;
    };

};