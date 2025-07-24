#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        // Node(int data){
        //     data = data;
        //     next = nullptr;
        // }
        Node(int data) : data(data), next(nullptr) { };
};


class LinkedList{
    private:
        Node* head;
    public:
        // LinkedList() : head(nullptr) {};
        LinkedList(){
            head = nullptr;
        }

        void insertAtTheBegining(int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        void insertAtEnd(int val){
            Node* newNode = new Node(val);
            if (head == nullptr){
                head = newNode;
                return;
            } 
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next =  newNode; 


        }

        void reverseList(){
            Node* prev = nullptr;
            Node* next = nullptr;
            Node* curr = head;

            while (curr != nullptr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
            


        }

        bool deleteVal(int val){
            if(head == nullptr){
                return false;
            }
            if (head->data == val){
                Node* temp = head;
                head = head->next;
                delete temp;
                return true;
            }

            Node* current = head;
            while (current->next != nullptr && current->next->data != val){
                current = current->next;
            }
            if (current->next != nullptr){
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            return false;

        }

       int countNodes(){

        int count = 0;
        Node* temp = head;
        while(temp != nullptr){
            count ++;
            temp = temp->next;
        }
        return count;
        }



        void display(){
            Node* temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "nullptr" << endl;

        }


};

int main(){
    LinkedList* ll = new LinkedList();
    cout << "Count of the list " << ll->countNodes() << endl;
    ll->insertAtTheBegining(5);
    cout << "Count of the list " << ll->countNodes() << endl;
    ll->insertAtTheBegining(10);
    cout << "Count of the list " << ll->countNodes() << endl;
    ll->insertAtTheBegining(20);
    cout << "Count of the list " << ll->countNodes() << endl;
    ll->insertAtEnd(15);
    cout << "Count of the list " << ll->countNodes() << endl;
    cout << "Before Deletion" << endl;
    int count = ll->countNodes();
    cout << "Count of the list " << count << endl;
    ll->display();
    // ll->deleteVal(5);
    ll->reverseList();
    
    cout << "After Deletion" << endl;
    ll->display();

    return 0;
}