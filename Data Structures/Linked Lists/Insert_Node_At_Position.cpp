SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    
    SinglyLinkedListNode *x= new SinglyLinkedListNode(0);
    SinglyLinkedListNode *y= new SinglyLinkedListNode(0);
    x=llist;
    y=x;
    for(int i =0;i<position;i++){
        if(x==nullptr){
            break;
        }
        y=x;
        x=x->next;

    }
    SinglyLinkedListNode *n=new SinglyLinkedListNode(0);
    n->data=data;
    if(y==nullptr){
        n->next=x;
        return n;
    }
    y->next=n;
    n->next=x;
    return llist;

}
