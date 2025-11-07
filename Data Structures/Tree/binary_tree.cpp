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
