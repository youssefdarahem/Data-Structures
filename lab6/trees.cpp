
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST{
public:
    Node* root;
    BST() : root(nullptr){}

    void insert(int val){
        root = insertRec(root, val);
    }


private:
    Node* insertRec(Node* node, int val){
        if(node == nullptr){
            return new Node(val);
        }

        if(val < node->data){
            node->left = insertRec(node->left, val);
        }else if (val > node->data){
            node->right = insertRec(node->right, val);
        }
        return node;

    }

};



int main(){
    return 0;
}