/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/



    Node * insert(Node * root, int data) {
        Node *x = root;
        
        if(x==nullptr){
            return new Node(data);
        }
        
        while(true){
            
            
            if(data>x->data){
                
                 if(x->right==nullptr){
                    x->right=new Node(data);
                    break;
                }
                else{
                    x=x->right;
                }
            }
            else if(data<x->data){
                 if(x->left==nullptr){
                    x->left=new Node(data);
                    break;
                }
                else{
                    x=x->left;
                }
            }
            else break;
            
           
  
        }

        return root;
    }
