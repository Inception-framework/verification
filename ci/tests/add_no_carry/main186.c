#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xf2"); 
  __asm volatile("mov R11,#0xd4"); 
  __asm volatile("ADD R5, R10, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
