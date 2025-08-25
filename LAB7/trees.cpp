
#include <string>
#include <iostream>

using namespace std;
class TreeNode
{
public:
    int key;
    string payload;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode *parent;

    TreeNode(int key, string payload, TreeNode *parent = NULL, TreeNode *left = NULL, TreeNode *right = NULL)
    {
        this->key = key;
        this->payload = payload;
        this->leftChild = left;
        this->rightChild = right;
        this->parent = parent;
    }

    TreeNode *hasLeftChild()
    {
        return this->leftChild; // True if not null, false otherwise
    }

    TreeNode *hasRightChild()
    {
        return this->rightChild; // True if not null, false otherwise
    }

    bool isLeftChild()
    {
        return this->parent && this->parent->leftChild == this;
    }

    bool isRightChild()
    {
        return this->parent && this->parent->rightChild == this;
    }

    bool isRoot()
    {
        return !this->parent;
    }

    bool isLeaf()
    {
        // return !this->rightChild && !this->leftChild;
        return !(this->rightChild || this->leftChild);
    }

    bool hasAnyChildren()
    {
        return this->rightChild || this->leftChild;
    }

    bool hasBothChildren()
    {
        return this->rightChild && this->leftChild;
    }

    void replaceNodeData(int key, string value, TreeNode *lc = NULL, TreeNode *rc = NULL)
    {
        this->key = key;
        this->payload = value;
        this->leftChild = lc;
        this->rightChild = rc;
        if (this->hasLeftChild())
        {
            this->leftChild->parent = this;
        }
        if (this->hasRightChild())
        {
            this->rightChild->parent = this;
        }
    }

    TreeNode *findSuccessor()
    {
        TreeNode *succ = NULL;
        if (this->hasRightChild())
        {
            succ = this->rightChild->findMin();
        }
        else
        {
            if (this->parent)
            {
                if (this->isLeftChild())
                {
                    succ = this->parent;
                }
                else
                {
                    this->parent->rightChild = NULL;
                    succ = this->parent->findSuccessor();
                    this->parent->rightChild = this;
                }
            }
        }
    }

    TreeNode *findMin()
    {
        TreeNode *current = this;
        while (current->hasLeftChild())
        {
            current = current->leftChild;
        }
        return current;
    }

    void spliceOut()
    {
        if (this->isLeaf())
        {
            if (this->isLeftChild())
            {
                this->parent->leftChild = NULL;
            }
            else
            {
                this->parent->rightChild = NULL;
            }
        }
        else if (this->hasAnyChildren())
        {
            if (this->hasLeftChild())
            {
                if (this->isLeftChild())
                {
                    this->parent->leftChild = this->leftChild;
                }
                else
                {
                    this->parent->rightChild = this->rightChild;
                }
                this->leftChild->parent = this->parent;
            }
            else
            {
                if (this->isLeftChild())
                {
                    this->parent->leftChild = this->rightChild;
                }
                else
                {
                    this->parent->rightChild = this->rightChild;
                }
                this->rightChild->parent = this->parent;
            }
        }
    }
};

class BinarySearchTree
{
private:
    TreeNode *root;
    int size;

    void _put(int key, string val, TreeNode *currentNode)
    {
        if (key < currentNode->key)
        {
            if (currentNode->hasLeftChild())
            {
                this->_put(key, val, currentNode->leftChild);
            }
            else
            {
                currentNode->leftChild = new TreeNode(key, val, currentNode);
            }
        }
        else
        {
            if (currentNode->hasRightChild())
            {
                this->_put(key, val, currentNode->rightChild);
            }
            else
            {
                currentNode->rightChild = new TreeNode(key, val, currentNode);
            }
        }
    }

    TreeNode *_get(int key, TreeNode *currentNode)
    {
        if (!currentNode)
        {
            return NULL;
        }
        else if (currentNode->key == key)
        {
            return currentNode;
        }
        else if (key < currentNode->key)
        {
            return this->_get(key, currentNode->leftChild);
        }
        else
        {
            return this->_get(key, currentNode->rightChild);
        }
    }

public:
    BinarySearchTree()
    {
        this->root = NULL;
        this->size = 0;
    }

    int length()
    {
        return this->size;
    }

    void put(int key, string val)
    {
        if (this->root)
        {
            this->_put(key, val, this->root);
        }
        else
        {
            this->root = new TreeNode(key, val);
        }
        this->size = this->size + 1;
    }

    string get(int key)
    {
        if (this->root)
        {
            TreeNode *res = this->_get(key, this->root);
            if (res)
            {
                return res->payload;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }

    void del(int key)
    {
        if (this->size > 1)
        {
            TreeNode *nodeToRemove = this->_get(key, this->root);
            if (nodeToRemove)
            {
                this->remove(nodeToRemove);
                this->size = this->size - 1;
            }
            else
            {
                cerr << "Error, key not in the tree" << endl;
            }
        }
        else if (this->size == 1 && this->root->key == key)
        {
            this->root = NULL;
            this->size = 0;
        }
        else
        {
            cerr << "Error, key not in the tree" << endl;
        }
    }

    void remove(TreeNode *currentNode)
    {
        if (currentNode->isLeaf())
        {
            if (currentNode == currentNode->parent->leftChild)
            {
                currentNode->parent->leftChild = NULL;
            }
            else
            {
                currentNode->parent->rightChild = NULL;
            }
        }
        else if (currentNode->hasBothChildren())
        {
            TreeNode *succ = currentNode->findSuccessor();
            succ->spliceOut();
            currentNode->key = succ->key;
            currentNode->payload = succ->payload;
        }
        else // this node has one child
        {
            if (currentNode->hasLeftChild())
            {
                if (currentNode->isLeftChild())
                {
                    currentNode->leftChild->parent = currentNode->parent;
                    currentNode->parent->leftChild = currentNode->leftChild;
                }
                else if (currentNode->isRightChild())
                {
                    currentNode->leftChild->parent = currentNode->parent;
                    currentNode->parent->rightChild = currentNode->leftChild;
                }
                else
                {
                    currentNode->replaceNodeData(currentNode->leftChild->key, currentNode->leftChild->payload, currentNode->leftChild->leftChild, currentNode->leftChild->rightChild);
                }
            }
            else
            {
                if (currentNode->isLeftChild())
                {
                    currentNode->rightChild->parent = currentNode->parent;
                    currentNode->parent->leftChild = currentNode->rightChild;
                }
                else if (currentNode->isRightChild())
                {
                    currentNode->rightChild->parent = currentNode->parent;
                    currentNode->parent->rightChild = currentNode->rightChild;
                }
                else
                {
                    currentNode->replaceNodeData(currentNode->rightChild->key, currentNode->rightChild->payload, currentNode->rightChild->leftChild, currentNode->rightChild->rightChild);
                }
            }
        }
    }

    TreeNode *getRoot()
    {
        return this->root;
    }
};

int main()
{

    BinarySearchTree *bst = new BinarySearchTree();
    cout << "Current Length of tree: " << bst->length() << endl;
    bst->put(5, "data1");
    bst->put(1, "data2");
    bst->put(7, "data3");
    cout << "Current Length of tree: " << bst->length() << endl;
    cout << "get value at 5: " << bst->get(5) << endl;
    cout << "get value at 1: " << bst->get(1) << endl;
    cout << "get value at 7: " << bst->get(7) << endl;
}