#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x24"); 
  __asm volatile("ADD R4, R2, #0x9a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
