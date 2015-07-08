
#include <stdio.h>
#include <string.h>

#include "list.h"

// Helper Functions
void p(void *d) { printf("--> %s\n",(char *)d); }
void *q(void *d) { char *s; asprintf(&s,"<%s>",(char *)d); return s; }
int cf(void *a,void *b) { return strcmp((const char *)a,(const char *)b); }
void *df(void *i) { return (void *)strdup((const char *)i); } 
int sf(const void *i,const void *j) { 
    return atoi(*(const char **)i) - atoi(*(const char **)j); 
}

int main(int argc, char **argv) {
    list *l = list_init();
    char *s;
    int i;
    for (i=0;i<10;++i) {
        asprintf(&s,"%d",i);
        list_append(l,s);
    }
    // Print list
    list_apply(l,p);
    // Prepend 'Hello'
    asprintf(&s,"Hello");
    list_prepend(l,s);
    // Map & print
    list *m = list_map(l,q);
    list_apply(m,p);
    // Length
    printf("Len = %d\n", list_count(l));
    // Find nth element
    listNode *after;
    if ((after = list_nth(l,10)) != NULL) {
        printf("Index: %s\n", (char *)(after->item));
        // Insert
        asprintf(&s,"There");
        list_insert(l,after,s);
        list_apply(l,p);
    }
    if ((after = list_nth(l,-1)) != NULL) {
        printf("Index (-1): %s\n", (char *)(after->item));
    }
    if ((after = list_nth(l,-2)) != NULL) {
        printf("Index (-2): %s\n", (char *)(after->item));
    }
    // Index
    listNode *x;
    if ((x = list_find(l,"There",cf)) != NULL) {
        printf(">> Found: %s\n",(char *)(x->item));
    }
    // Remove
    listNode *r;
    printf(">> Removing head\n");
    list_remove(l,l->head,free);
    list_apply(l,p);
    printf(">> Removing tail\n");
    list_remove(l,l->tail,free);
    list_apply(l,p);
    printf(">> Removing 5th element\n");
    list_remove(l,list_nth(l,5),free);
    list_apply(l,p);
    // Slice
    printf("Slice: 5:10\n");
    list *slice = list_slice(l,5,10,df);
    list_apply(slice,p);
    printf("Slice: -5:-2\n");
    list *slice2 = list_slice(l,-5,-2,df);
    list_apply(slice2,p);
    printf("Concat:\n");
    list *concat = list_concat(slice,slice2,df);
    list_apply(concat,p);
    printf("Sort:\n");
    list_sort(concat,sf);
    list_apply(concat,p);

    // Free
    list_free(l,free);
    list_free(m,free);
    list_free(slice,free);
    list_free(slice2,free);
    list_free(concat,free);
    return 0;
}
