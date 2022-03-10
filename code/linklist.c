//structure of linked list with char and next pointer
typedef struct linklist list;
struct linklist
{
    char c;
    list * next;
};


//function to insert a char into the linked will create new list if its null
list* insert (list*l,char c){
    if (l==NULL)
    {
        l=(list*)malloc(sizeof(list));
        l->c = c;
        return l;
    }
    list* iter = l;
    while (iter->next)
    {
        iter = iter->next;
    }
    list * temp = (list*)malloc(sizeof(list));
    temp->c = c;
    temp->next = NULL;
    iter->next = temp;
    return l;
}


void debug(list* l){
    list * iter = l;
    while (iter)
    {
        printf("%c->",iter->c);
        iter = iter->next;
    }
    free(iter);
    printf("\n");
}