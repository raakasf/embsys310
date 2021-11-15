/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STACK_H__
#define __STACK_H__

void stack_init(void);
int stack_push(int data);
int stack_pop(void);
int is_stack_empty(void);
int is_stack_full(void);

#endif
