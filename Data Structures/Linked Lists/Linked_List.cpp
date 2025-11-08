#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->next = nullptr;
    }
    Node(int d){
        this->data = d;
        this->next = nullptr;
    }
    void set_next (Node* next){
        this->next = next;
    }
    Node* get_next(){
        return next;
    }
    friend class LinkedList;
};
class LinkedList{
    private:
    Node * head;
    
    public:
    LinkedList(){
        head = nullptr;
    }
    LinkedList(Node * head){
        this->head=head;
    }
    bool empty(){
        return head==nullptr;
    }
    int length(){
        Node * cur_node = head;
        int counter=0;
        while(cur_node){
            counter++;
            cur_node= cur_node->next;
        }
        return counter;
    }
    void push_front(int d){
        Node *n = new Node(d);
        n->next= head;
        head = n;
    }
    void pop_front(){
        if(this->empty()){
            return;
        }
        Node * cur_node = new Node;
        cur_node = head;
        head = head->next;
        delete cur_node;
        cur_node = nullptr;
    }
    void push_back(int d){
        Node * node = new Node(d);
        if(empty()){
            push_front(d);
            return;
        }
        Node * cur_node = head;
        while(true){
            if(cur_node->next==nullptr){
                cur_node->next = node;
                break;
            }
            cur_node=cur_node->next;

        }
    }




};
bool AreEqual(Node *head1,Node*head2){
    if(head1==nullptr&&head2==nullptr)return true;
    else if((!head1 && head2)||(head1&&!head2)) return false;
    if(head1->data==head2->data)return AreEqual(head1->next,head2->next);
    else return false;
}
int main(){
Node * h1 = new Node;
h1->data = 10;
Node * h2 = new Node;
h2->data=10;

LinkedList l1(h1);
LinkedList l2(h2);
l1.push_back(20);
l2.push_back(20);
cout<<AreEqual(h1,h2);
}
