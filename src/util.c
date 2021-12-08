#include <stdlib.h>
#include <stdio.h>

// stderr fputs wrapper
void eputs(char *s) {
    fprintf(stderr, "%s\n", s);
}

// simple null checking procedure
void nullcheck(void *ptr, char *msg) {
    if(ptr == NULL) {
        fprintf(stderr, "Error (Unexpected Null Value): %s\n", msg);
        exit(1);
    }
}
