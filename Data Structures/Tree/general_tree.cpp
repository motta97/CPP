template <typename T>
class node{
    public:
    T data;
    vector<*node>children;
    
    node(T d){
        data = d;
    }
    ~node(){
        for(auto child: children){
            delete child;
        }
    }
};
void printTreeInt(node<int>* root,int level = 0){
    if(root==nullptr)return;
    //this makes an indentation based on depth
    for(int i = 0;i< level;i++){
        cout<<"- "<<root->data<<endl;
    }

    for(auto child:root->children){
        printTreeInt(child,level+1);
    }

}
