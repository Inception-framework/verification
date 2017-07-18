#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xa5"); 
  __asm volatile("mov R8,#0xe9"); 
  __asm volatile("ADD R12, R5, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
