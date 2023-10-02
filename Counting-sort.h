#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

void countingSort(int arr[], int n) {
    
    int max_element = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    int count[max_element + 1];
    for(int i = 0; i <= max_element; i++) {
        count[i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    // Modify the count array so that it contains the actual position of each element in the sorted array
    for(int i = 1; i <= max_element; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted elements
    int temp[n];
    for(int i = 0; i < n; i++) {
        temp[i] = 0;
    }

    // Fill the temporary array with the sorted elements from the count array
    for(int i = n - 1; i >= 0; i--) {
        temp[--count[arr[i]]] = arr[i];
    }

    // Copy the sorted elements from the temporary array to the original array
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

#endif

