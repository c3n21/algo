#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 5

typedef struct s_item * Item;
typedef struct s_queue * Queue;

void printItem(Item item);

Item * makeItem (int n);

Queue * queue();
// Put element on rear
void enqueue ( Queue queue , Item item );
// Remove and return element from front
Item dequeue ( Queue queue );
// Return front element
Item frontValue ( Queue queue );
// Check if queue is empty
int is_empty_queue ( Queue queue );
// Print queue content
void print_queue ( Queue queue );

#endif
