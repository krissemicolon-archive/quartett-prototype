#include <stdlib.h>
#include <stdio.h>

// stderr fputs wrapper
void eputs(char *s) {
    fputs(s, stderr);
}

// simple null checking procedure
void nullcheck(void *ptr, char *msg) {
    if(ptr == NULL) {
        fprintf(stderr, "Error (Unexpected Null Value): %s", msg);
        exit(1);
    }
}
