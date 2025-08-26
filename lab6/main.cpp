#include<iostream>

void bubbleSort(int arr[], int n){
    bool swapped;
    for( int i = 0;i < n;i++){
        swapped = false;
        for (int j = 0; j < n -i -1; j++){
            if (arr[j] > arr[j+1]){
                
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void insertionSort(int arr[], int size){
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }


}



void printArr(int arr[],int size){
 
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}



int main(){
    int arr[] = {15,45,5,48,2,4,10};
    int n = sizeof(arr) / sizeof(int);
    printArr(arr,n);
    insertionSort(arr,n);
    printArr(arr,n);
    return 0;
}