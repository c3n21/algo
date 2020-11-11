#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
#include "debug.h"
#include "set.h"

/**
 * OVERVIEW: programma che le legge da STDIN una sequenza di istruzioni secondo il formato della tabella,
 * dove n è intero. I vari elementi sulla riga sono separati da uno o più spazi.
 * Quando una riga è letta viene eseguita l'operazione associata; le operazioni di stampa sono effettuate su
 * STDOUT e ogni operazione deve iniziare su una nuova riga
 *
 * _________________________________
 * |INPUT |       OP      | OPCODE |
 * ---------------------------------
 * |+ n   | add n         |   0    |
 * |- n   | delete n      |   1    |
 * |? n   | n is in set   |   2    |
 * |  c   | print size    |   3    |
 * |  p   | print as is   |   4    |
 * |  d   | delete        |   5    |
 * |  f   | exit          |   6    |
 * ---------------------------------
 */

/**
 * DATATYPES */

enum OPCODE{
        ADD = 0,
        DEL,
        IS_IN,
        SIZE,
        PRINT,
        DEL_A,
        EXIT
} OPCODES;

/**
 * [PROTOTYPES]
 */
void parse(char * str, int * res);

int main(int argc, char * args[]) {
        Set * set = set_new();
        char buffer[1024] = "\0";
        int res[2] = {0};

        while (res[0] != EXIT) {
                printf(">");
                fgets(buffer, 1024, stdin);
                debug_print("[MAIN::MAIN] input = %s;\n", buffer);

                parse(buffer, res);
                if (res[0] != -1) {
                        debug_print("[MAIN::MAIN] [OPERATION] %d [OPERAND] %d\n", res[0], res[1]);
                }

                switch (res[0]) {
                        case ADD:
                                set_add(set, res[1]);
                                break;
                        case DEL:
                                set_delete(set, res[1]);
                                break;
                        case IS_IN:
                                printf("[IS IN] %s;\n", set_search(set, res[1]) == NULL? "FALSE" : "TRUE");
                                break;
                        case SIZE:
                                printf("[SIZE] %d;\n", set->size);
                                break;
                        case PRINT:
                                set_print(set);
                                break;
                        case DEL_A:
                                set_clear(set);
                                break;
                        case EXIT:
                                res[1] = EXIT;                
                                break;
                }
        }
        return 0;
}

void parse(char * restrict str, int * restrict res) {
        /**
         * [REQUIRES] 
         *      str must be non-NULL and follow the format "[OP] [OPERAND]" with at least a whitespace in-between trailing whitespaces will be ignored;
         *      res must be sizeof(int)*2
         * [EFFECT]   
         *      return in the res buffer the op-code of the operation (index 0) and the eventual operand (index 1)
         *      if the input is malformed (there is no operation available) or in case of error -1 will be returned
         *      well-formed input "-      n"
         *      malformed input "- asdfasdf n"
         */
        res[0] = -1;
        res[1] = -1;
        int i = 0;

        for (; i < 1023 && str[i] == ' '; i++); //ignore trailing spaces         

        debug_print("[MAIN::PARSE] i = %d;\n", i);

        switch (str[i]) {
                case '+':
                        res[0] = ADD;
                        break;
                case '-':
                        res[0] = DEL;
                        break;
                case '?':
                        res[1] = IS_IN;
                        break;
                case 'c':
                        res[0] = SIZE;
                        break;
                case 'p':
                        res[0] = PRINT;
                        break;
                case 'd':
                        res[0] = DEL_A;
                        break;
                case 'f':
                        res[0] = EXIT;
                        break;
        }

        debug_print("[MAIN::PARSE] OP = %c;\n", str[i]);
        debug_print("[MAIN::PARSE] str w/o OP = %s;\n", (str+i+1));
        //seek for the beginning of the operand
        //for (; i < 1023 && str[i] == ' '; i++); //ignore trailing spaces         

        //seeking for the end of the operand
        res[1] = strtol(str+i+1, NULL, 10);
        debug_print("[MAIN::PARSE] OPCODE = %d; OPERAND = %d;\n", res[0], res[1]);
}
