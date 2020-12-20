#include <iostream>
#include <vector>
#include <string>

using namespace std;

int partition(vector<int> &arr, int start, int end ) {
    int index = start;
    int pivot = arr[end - 1];
    for (int i = start; i < end; i++) {
        if (arr[i] <=  pivot) {
            if (index < i) {
                int tmp = arr[index];
                arr[index] = arr[i];
                arr[i] = tmp;
            }    
            index++;
        }
    }
    return index;
}

int quick_sort(vector<int> &arr, int start, int end ) {
    if (start >= end) return 0;
    
    int index = partition(arr, start, end);
    quick_sort(arr, start, index - 1);
    quick_sort(arr, index, end);
}

int main(void){
    string input;
    vector<int> arr;
    
    while (cin >> input) {
      if (input == "#") break;
        arr.push_back(std::stoi(input));
    }
    std::cout << "Input:" << std::endl;    
    for (int i = 0; i < arr.size(); ++i) std::cout << arr[i] << " "; 
    
    std::cout << std::endl;
    auto ret = quick_sort(arr,  0, arr.size());

    std::cout << "Output:" << std::endl;
    for (int i = 0; i < arr.size(); ++i) std::cout << arr[i] << " "; 
    std::cout << std::endl;
    
    return 0;
}