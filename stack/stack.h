/*
 * minhapilha.h
 *
 *  Created on: Jun 21, 2015
 *      Author: arcanosam
 */

#ifndef STACK_STACK_H_
#define STACK_STACK_H_

struct stack * push (struct stack *frame, int item);
void list_stack (struct stack *frame);
int search_by_item (struct stack *frame, int item);
int stack_size (struct stack *frame);
struct stack * remove_by_value (struct stack *frame, int item);

#endif /* STACK_STACK_H_ */
