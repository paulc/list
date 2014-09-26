
#include <stdio.h>
#include <string.h>

#include "list.h"

int main(int argc, char **argv) {
    list *l = list_init();
    char *s;
    int i;
    for (i=0;i<10;++i) {
        asprintf(&s,"%d",i);
        list_append(l,s);
    }
    // Helper Functions
    void p(void *d) { printf("--> %s\n",(char *)d); }
    void *q(void *d) { char *s; asprintf(&s,"<%s>",(char *)d); return s; }
    int cf(void *a,void *b) { return strcmp((const char *)a,(const char *)b); }
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
    // Index
    listNode *x;
    if ((x = list_find(l,"There",strcmp)) != NULL) {
        printf(">> Found: %s\n",(char *)(x->item));
    }
    // Free
    list_free(l,free);
    list_free(m,free);
    return 0;
}
