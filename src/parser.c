#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "config.h"
#include "tokens.h"
#include "util.h"

#define MAX_SCHEMA_SIZE 16
#define SCHEMA_BUF_SIZE 64

void parse() {
    char buffer[SCHEMA_BUF_SIZE];
    token current = None;
    char schema[MAX_SCHEMA_SIZE][SCHEMA_BUF_SIZE];
    size_t schema_size = 0;
    size_t schema_current = 0;
    bool in_schema = false;
    bool in_card = false;
    bool in_set = false;

    FILE *cards = fopen(CARDS_CONFIG, "r");
    nullcheck(cards, "Card Configuration File Path");

    while(fscanf(cards, "%s", &buffer) == true) {
        // validating tokens and assigning them to current token enum
        if(strcmp(buffer, SCHEMA) == 0) {
            current = Schema;
        } else if(strcmp(buffer, CARD) == 0) {
            current = Card;
        } else if(strcmp(buffer, LPAREN) == 0) {
            current = Lparen;
        } else if(strcmp(buffer, RPAREN) == 0) {
            current = Rparen;
        } else if(strcmp(buffer, SET) == 0) {
            current = Set;
        } else {
            current = None;
        }

        if(current != None) {
            if(current == Schema) in_schema = true;
            if(current == Card)   in_card = true;
            if(current == Set)    in_set = true;
            if(current == Rparen) {
                in_schema = in_card = in_set = false;
            }
        } else if(in_schema || in_card || in_set) {
            if(in_schema && in_set) {
                printf("Schema Set: %s\n", buffer);
                strcpy(schema[schema_size], buffer);
                schema_size++;
            }
            if(in_card && in_set) {
                printf("Card Set: %s\n", buffer);
                if(schema_current < schema_size) {
                    schema_current++;
                } else {
                    schema_current = 0;
                }
            }
        } else {
            eputs("Error (Cards Parser): Invalid Token");
        }
    }

    if(schema_current != 0) {
        eputs("Error (Cards Parser): Schema Was Filled Inexpectedly");
    }

    // TODO: Optimize with schema_current
    // filling keys
    for(int i = 0; i < schema_size; i++) {
        
    }
}
