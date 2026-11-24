#include <iostream>

#include "GenericArray.h"

int main() {
    GenericArray<int> int_array;
    
    int_array.addElement(1);
    int_array.addElement(3);
    int_array.addElement(5);
    int_array.addElement(7);
    int_array.addElement(9);
    int_array.addElement(21);
    int_array.addElement(23);
    int_array.addElement(25);

    std::cout << "\nsize of array is: " << int_array.size() << std::endl;
    std::cout << "sum of the array is: " << int_array.sum() << std::endl;
    std::cout << "maximum and minimum of array is: " << int_array.max() << "\t" << int_array.min() << std::endl;
    
    int begin_idx = 2;
    int end_idx = 5;
    int *sliced_array = int_array.slice(begin_idx, end_idx);
    
    //only print if the slice worked
    if (sliced_array != nullptr) {
        std::cout << "sliced array (" << begin_idx << " to " << end_idx << ") is: [";
        int slice_size = end_idx - begin_idx + 1;
        for(int i = 0; i < slice_size; i++) {
            std::cout << sliced_array[i];
            if (i < slice_size - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;

        //deleting pointer returned by slice function 
        delete[] sliced_array;
    }

    return 0;
}
