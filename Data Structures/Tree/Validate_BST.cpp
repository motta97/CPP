
#include<vector>
    bool checkBST(Node* root) {
     
        if(root==nullptr) return true;
        if(root->left==nullptr && root->right==nullptr){
            return true;
        }
        return checkBST(root->left)&&checkBST(root->right)&&is_Smaller_Than_All(root)&&is_Greater_Than_All(root);
             
        
    }

void traverse(Node* root, vector<int> &v){
    if(root==nullptr)return;
    v.push_back(root->data);
    traverse(root->left,v);
    traverse(root->right,v);
    
}
bool is_Greater_Than_All(Node* root){
    vector<int> v;
    traverse(root->left,v);
    for(int i=0;i<v.size();i++){
        if(v[i]>=root->data)return false;
    }
    return true;   
}
bool is_Smaller_Than_All(Node* root){
     vector<int> v;
    traverse(root->right,v);
    for(int i=0;i<v.size();i++){
        if(v[i]<=root->data)return false;
    }
    return true; 
}
