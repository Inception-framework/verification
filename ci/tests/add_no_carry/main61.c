#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xd5"); 
  __asm volatile("mov R5,#0x01"); 
  __asm volatile("ADD R0, R6, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
