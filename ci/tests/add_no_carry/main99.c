#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xcf"); 
  __asm volatile("ADD R2, R9, #0xd8b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
