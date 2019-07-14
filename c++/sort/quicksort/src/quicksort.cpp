#include <iostream>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void swap(int &a, int &b) {
    std::cout << "swap: " << a << " " << b << std::endl;
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int arr[], int low, int high, int size) {
    std::cout << "partition: " << low << " " << high << std::endl;
    int i = low;
    int j = high;
    int pi = (i + j) / 2;
    int pivot = arr[pi];
    std::cout << "pivot: at [" << pi << "]: " << pivot << std::endl;
    while (i < j) {
        std::cout << "while: " << std::endl;
        printArray(arr, size);
        while (arr[i] < pivot) {
            i++;
            std::cout << "i: " << i << std::endl;
        }
        while (arr[j] > pivot) {
            j--;
            std::cout << "j: " << j << std::endl;
        }
        std::cout << "i: " << i << " j: " << j << std::endl;
        if (i < j)
            swap(arr[i], arr[j]);
        if (arr[i] == arr[j] && i+j)
            break;
    }
    return (i + j) / 2;
}

void quickSort(int arr[], int low, int high, int size) {
    int pi = partition(arr, low, high, size);
    std::cout << "pi: " << pi << std::endl;
    if (pi > low)
        quickSort(arr, low, pi, size);
    if (pi + 1 < high)
        quickSort(arr, pi + 1, high, size);
}


int main() {
    int arr[] = {10, 7, 7, 8, 9, 1, 1, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
//    quickSort0(arr, 0, n - 1);
    quickSort(arr, 0, n - 1, n);
    std::cout << "Quick Sort: " << n << std::endl;
//    std::cout << "Sorted array: " << n << std::endl;
    printArray(arr, n);
    return 0;
}