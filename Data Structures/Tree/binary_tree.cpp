template <typename T>
class binary_tree_node{
    public:
    T data;
    binary_tree_node *left_child;
    binary_tree_node *right_child;

};
binary_tree_node<int> * binary_search(binary_tree_node<int> *t,int key){
    if(t==nullptr)return nullptr;
    else if(t->data==key)return t;
    else if(t->data>key)return binary_search(t->left_child,key);
    else return binary_search(t->right_child,key);
}
binary_tree_node<int> * binary_search_loop(binary_tree_node<int> *t,int key){
    while (t){
    if(t->data==key)return t;
    else if(t->data>key)return t=t->left_child;
    else return t=t->right_child;
    }
    return nullptr;
}
void insert(binary_tree_node<int> * t,int key ){
    binary_tree_node <int> *r = nullptr, *p;
    while(t!=nullptr){
        //tailing pointer
        r = t;
        if(t->data==key)return;
        else if(t->data>key){
            t=t->left_child;
        }
        else t= t->right_child;

    }
    p = new binary_tree_node<int>;
    p->left_child=p->right_child=nullptr;
    p->data=key;
    if(key>r->data)r->right_child=p;
    else r->left_child=p;

    //for creating a BST, we can create only a root, and then
    //insert the rest of the elements using this function

}
void printBinaryTreeInt(binary_tree_node<int>* n){
    if(n==nullptr)return;
   
    cout<<n->data<<" ";
    printBinaryTreeInt(n->left_child);
    printBinaryTreeInt(n->right_child);
}
