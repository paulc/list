
#include "buffer.h"

buf *buf_init(size_t n) {
    buf *b = malloc(sizeof(buf));
    assert(b);
    b->size = n;
    b->used = 0;
    b->data = malloc(n+1);
    assert(b->data);
    memset(b->data,255,n+1);
    return b;
}

void buf_free(buf *b) {
    free(b->data);
    free(b);
}

void buf_append(buf *b, void *d, size_t n) {
    while ((b->used + n) > b->size) {
        b->size *= 2;
        b->data = realloc(b->data,b->size+1);
        assert(b->data);
    }
    memcpy(b->data + b->used, d, n);
    b->used += n;
    memset(b->data + b->used, 0, 1);
}

void buf_append_str(buf *b, char *s) {
    size_t n = strlen(s);
    buf_append(b,s,strlen(s));
}

void buf_print(buf *b) {
    size_t n;
    printf("b->size: %zu / b->used: %zu\n",b->size,b->used);
    for (n = 0; n < b->used; ++n) {
        if (isalnum(*(char *)(b->data + n))) {
            printf("%c",*(char *)(b->data + n));
        } else {
            printf("<%02x>",*(unsigned char *)(b->data + n));
        }
    }
    printf("\n");
}
