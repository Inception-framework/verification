#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xaa"); 
  __asm volatile("ADD R9, R7, #0x7c");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
