SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    stack<SinglyLinkedListNode*> s;

    SinglyLinkedListNode *x = new SinglyLinkedListNode(0);
    SinglyLinkedListNode *newHead = new SinglyLinkedListNode(0);
    SinglyLinkedListNode *tmp = new SinglyLinkedListNode(0);

    x=llist;
    while(x!=nullptr){
        s.push(x);
        x=x->next;
    }
    newHead=s.top();
    tmp=newHead;
    s.pop();
    while(!s.empty()){
        tmp->next=s.top();
        s.pop();
        tmp=tmp->next;
    }
    tmp->next=nullptr;
    return newHead;

}
