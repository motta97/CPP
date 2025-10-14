linkeList* search_in_a_linked_list_recursive(linkeList* l,int d){
    //we want to traverse the whole linked list, and return true
    //if we found a matched item, otherwise, return false
    if(l){
        if(l->data==d)return l;
        return search_in_a_linked_list(l->next,d);
    }
    return NULL;

}
