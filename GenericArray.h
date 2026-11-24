#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <iostream>

template <typename T>
class GenericArray {
private:
    T* data;
    int current_size;

public:
    GenericArray();
    ~GenericArray();
    
    void addElement(T param);
    T at(int param);
    int size();
    T sum();
    T max();
    T min();
    T* slice(int begin, int end);
};

template <typename T>
GenericArray<T>::GenericArray() {
    data = nullptr;
    current_size = 0;
}

//free the memory when the object is destroyed
template <typename T>
GenericArray<T>::~GenericArray() {
    delete[] data;
}

template <typename T>
void GenericArray<T>::addElement(T param) {
    //d.memory alloc and clean up
    //alloc new space, copy over previous array, add new element, and delete old array before update 
    T* new_data = new T[current_size + 1];
    
    for (int i = 0; i < current_size; i++) {
        new_data[i] = data[i];
    }
    
    new_data[current_size] = param;
    
    delete[] data;
    
    data = new_data;
    current_size++;
}

template <typename T>
T GenericArray<T>::at(int param) {
    if (param < 0 || param >= current_size) {
        std::cout << "error: index " << param << " is out of bounds" << std::endl;
        return 0;
    }
    return data[param];
}

template <typename T>
int GenericArray<T>::size() {
    return current_size;
}

template <typename T>
T GenericArray<T>::sum() {
    T total = 0;
    for (int i = 0; i < current_size; i++) {
        total += data[i];
    }
    return total;
}

template <typename T>
T GenericArray<T>::max() {
    if (current_size == 0) {
        std::cout << "error: array is empty" << std::endl;
        return 0;
    }
    T max_val = data[0];
    for (int i = 1; i < current_size; i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
    }
    return max_val;
}

template <typename T>
T GenericArray<T>::min() {
    if (current_size == 0) {
        std::cout << "error: array is empty" << std::endl;
        return 0;
    }
    T min_val = data[0];
    for (int i = 1; i < current_size; i++) {
        if (data[i] < min_val) {
            min_val = data[i];
        }
    }
    return min_val;
}

template <typename T>
T* GenericArray<T>::slice(int begin, int end) {
    //check the bounds > return nullptr if they are bad
    if (begin < 0 || end >= current_size || begin > end) {
        std::cout << "error: slice (" << begin << " to " << end << ") is out of bounds" << std::endl;
        return nullptr;
    }
    
    //create new dynamically allocated array for the slice
      int slice_size = end - begin + 1;
    T* sliced_array = new T[slice_size];
    
    for (int i = 0; i < slice_size; i++) {
        sliced_array[i] = data[begin + i];
    }
    
    return sliced_array;
}

#endif
