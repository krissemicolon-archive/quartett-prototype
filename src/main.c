#include <stdlib.h>
#include <stdio.h>

#include "parser.h"
#include "hashtable.h"
#include "linked.h"
#include "util.h"

int main() {
    dump_linked(parse());

    return 0;
}
