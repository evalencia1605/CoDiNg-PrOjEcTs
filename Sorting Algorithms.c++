#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Insertion-sort.h"
#include "Quick-sort.h"
#include "Bubble-sort.h"
#include "Selection-sort.h"
#include "Counting-sort.h"
#include "Merge-sort.h"
#include "Heap-sort.h"
#include "Shell-sort.h"

using namespace std;

int main() {
    // Prompt user to select a sorting algorithm
    cout << "Please select a sorting algorithm:" << endl;
    cout << "1. Insertion Sort" << endl;
    cout << "2. Quick Sort" << endl;
    cout << "3. Bubble Sort" << endl;
    cout << "4. Selection Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "6. Counting Sort" << endl;
    cout << "7. Heap Sort" << endl;
    cout << "8. Shell Sort" << endl;
    int option;
    cin >> option;

    // Open file containing the numbers to be sorted
    ifstream inFile("random.txt");
    if (!inFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Read numbers from file into an array
    const int SIZE = 100000;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        inFile >> arr[i];
    }

    // Close the file
    inFile.close();

    // Sort the array using the selected algorithm and measure the time taken
    auto start = chrono::high_resolution_clock::now();
    if (option == 1) {
        insertion_sort(arr, SIZE);
    }
    else if (option == 2) {
        quickSort(arr, 0, SIZE - 1);
    }
    else if (option == 3) {
        bubbleSort(arr, SIZE);
    }
    else if (option == 4){
        selectionSort(arr, SIZE);
    }
    else if (option == 5){
        mergeSort(arr, 0, SIZE - 1);
    }
    else if (option == 6){
        countingSort(arr, SIZE);
    }
    else if (option == 7){
        heapSort(arr,SIZE);
    }
    else if (option == 8){
        shellSort(arr,SIZE);
    }
    else {
        cerr << "Invalid option selected." << endl;
        return 1;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    // Output the sorted array and the time taken
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time taken: " << duration.count() << "ms" << endl;

    return 0;
}

