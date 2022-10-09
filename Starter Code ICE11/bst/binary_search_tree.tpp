#include "binary_search_tree.h"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    clone(rhs.root);
}

// this is an alternative implementation using a stack to simulate the recursion
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clone(Node<KeyType, ItemType>* rhs)
{
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(const BinarySearchTree<KeyType, ItemType>& rhs)
{
    if (&rhs == this)
        return *this;

    destroy();

    root = 0;
    clone(rhs.root);

    return *this;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

// inserts a new node into the tree
// @param a key and an item
// @pre there cannot already be an instance of the key in the tree
// @post the node is inserted
// @return true if successful, false if not
template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    // if empty, insert as root
    if(root == NULL){
        Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>;
        newNode->data = item;
        newNode->key = key;
        root = newNode;
        return true;
    }// end if

    Node<KeyType, ItemType>* curr_parent;
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>;
    newNode->data = item;
    newNode->key = key;

    search(key, curr, curr_parent);

    // if item already exists
    if(curr->data == key){
        return false;
    }// end if

    // find where to enter
    curr = root;
    while(curr != 0){
        curr_parent = curr;
        if(key < curr->data){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }

    // insert appropriatly
    if(key < curr_parent->data){
        curr_parent->left = newNode;
    }else{
        curr_parent->right = newNode;
    }
    return true;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

// removes node from tree
// @param a key of type KeyType
// @pre key is in tree
// @post key is removed
// @return true if successfull, false if not
template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty())
        return false; // empty tree

    // TODO
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if(curr == NULL){
        
        return false;
    }

    // case one thing in the tree
    if(root->left == NULL && root->right == NULL){
        
        free(root);
        root = NULL;
        return true;

    }

    // case, found deleted item at leaf
    if(curr->left == NULL && curr->right == NULL){
        
        if(curr_parent->left == curr){
            curr_parent->left = NULL;
        }
        if(curr_parent->right == curr){
            curr_parent->right = NULL;
        }
        free(curr);
        
        return true;
    }

    // case, item to delete has only a right child
    if(curr->left == NULL && curr->right != NULL){
        
        if(curr_parent != NULL){
            if(curr_parent->left == curr){
            curr_parent->left = curr->right;
            }
            if(curr_parent->right == curr){
                curr_parent->right = curr->right;
            }
        }else{
            root = curr->right;
        }
        
        free(curr);
        return true;
    }

    // case, item to delete has only a left child
    if(curr->left != NULL && curr->right == NULL){
        
        if(curr_parent != NULL){
            if(curr_parent->left == curr){
            curr_parent->left = curr->left;
            }
            if(curr_parent->right == curr){
                curr_parent->right = curr->left;
            }
        }else{
            root = curr->left;
        }
        
        free(curr);
        return true;
    }

    // case, item to delete has two children
    if(curr->left != 0 && curr->right != 0){
        
        Node<KeyType, ItemType>* sucessor;
        inorder(curr, sucessor, curr_parent);
        if(curr_parent->left == curr){
            curr_parent->left = sucessor;
        }
        if(curr_parent->right == curr){
            curr_parent->right = sucessor;
        }
        free(curr);
        return true;
    }

    return false; // default should never get here
}

// finds the next node
// @param current node, node to find the next ordered node, parent node
// @post next node in ordered is set as the in node
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{

    // move right once
    curr = curr->right;

    in = curr->left;
    // move left as far as possible
    while(in->left != 0){
        in = in->left;
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}
