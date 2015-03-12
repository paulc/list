#include "buffer.h"

int main(int argc, char **argv) {
    buf *b = buf_init(10);
    buf_print(b);
    void *x = malloc(5);
    memset(x,15,5);
    buf_append(b,x,5);
    buf_print(b);
    free(x);
    buf_append(b,"hello",5);
    buf_print(b);
    buf_free(b);
    printf("-----\n");
    b = buf_init(10);
    buf_append(b,"hello",5);
    buf_print(b);
    buf_append(b,"hello",5);
    buf_print(b);
    buf_append(b,"hello",5);
    buf_print(b);
    buf_append(b,"hello",5);
    buf_append(b,"hello",0);
    buf_append(b,"hello",1);
    buf_print(b);
    buf_free(b);
    printf("-----\n");
    b = buf_init(10);
    buf_print(b);
    buf_append_str(b,"hello");
    buf_print(b);
    buf_append_str(b,"hello");
    buf_print(b);
    buf_append_str(b,"h");
    buf_print(b);
    buf_free(b);
    printf("-----\n");
    b = buf_init(10);
    buf_append_printf(b,"%08d %s\n",100,"hello");
    buf_append_printf(b,"%08d %s\n",100,"hello");
    buf_print(b);
    buf_free(b);
}


