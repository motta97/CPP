linkeList* search_in_a_linked_list(linkeList* l,int d){
    //we want to traverse the whole linked list, and return its address
    //if we found a matched item, otherwise, return NULL
    while(l){
        if(l->data==d)return l;
        l=l->next;
    }
    return NULL;

}
