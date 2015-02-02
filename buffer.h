
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    size_t used;
    void *data;
} buf;

buf *buf_init(size_t n);
void buf_append(buf *b, void *d, size_t n);
void buf_append_str(buf *b, char *s);
void buf_append_printf(buf *b, const char *format, ...);
void buf_free(buf *b);
void buf_print(buf *b);

