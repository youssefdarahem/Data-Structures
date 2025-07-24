#include <iostream>


#define MAX 10

using namespace std;

class Stack{
    private:
        int topIndex;
        int arr[MAX];


    public:
        Stack(){
            topIndex = -1;
        }

        bool isEmpty(){
            return topIndex == -1;
        }

        bool isFull(){
            return topIndex == MAX - 1;
        } 

        void push(int data){
            if(!isFull()){
                arr[++topIndex] = data;
                cout << data << " is pushed to the stack" << endl;
            }else{
                cout << "Stack is Full" << endl;
            }
        }

        void pop(){
            if(!isEmpty()){
                topIndex--;
            }else{
                cout << "Can't remove, stack is already empty!" << endl;
            }

        }

        int peak(){
            if(!isEmpty()){
                return arr[topIndex];
            }else{
               throw out_of_range("stack is empty!"); 
            }
        }


};

void reverseList(int arr[], int size){
    Stack s;
    for (int i = 0; i < size; ++i) {
        s.push(arr[i]);
    }
    for (int i = 0; i < size; ++i) {
        arr[i] = s.peak();
        s.pop();
    }

}

int main(){

    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: " << endl;
    for(int i : arr){
        cout << i << " ";
    }
    cout << endl;

    reverseList(arr,size);

    Stack s = Stack();
    cout << "status of the stack: " << s.isEmpty() << endl;
    for(int i= 0; i < 100; i=i+10){
        s.push(i);   
    }
    s.push(100);

    cout << "at the top: " << s.peak() << endl;

    cout << "status of the stack: " << s.isEmpty() << endl;
    
    return 0;
}





