#ifndef TEST_H
#define TEST_H

#include "../src/bist/bist.h"

int createBist(Item * items, const int size, Bist * root);
int createBit(Item *, const int size, Bit_node * root);
void createItems(Item *, const int size);

#endif
