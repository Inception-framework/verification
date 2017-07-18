#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xd5"); 
  __asm volatile("ADD R6, R0, #0xa4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
