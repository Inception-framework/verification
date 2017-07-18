#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xbd"); 
  __asm volatile("ADD R6, R1, #0x3b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
