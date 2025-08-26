#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int linearSearch(const vector<int> &vec, int key){
    for(int i = 0; i < vec.size(); i++){
        if (vec[i] == key){
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int> &vec, int target){
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right){
        int middle = left + (right - left) / 2;
        if (vec[middle] == target){
            return middle;
        }else if(vec[middle] < target){
            left = middle +1;
        }else{
            right = middle - 1;
        }
        
    }
    return -1;



}







int main(){
    vector<int> vec = {15,65,48,79,45,23,45,12,20};
    sort(vec.begin(),vec.end());
    
    for (auto i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";

    }
    cout << endl;
    
    cout << "searching for 15: " << binarySearch(vec,15) << endl; 
    cout << "searching for 45: " << binarySearch(vec,45) << endl; 
    cout << "searching for 100: " << binarySearch(vec,100) << endl; 
    return 0;
}