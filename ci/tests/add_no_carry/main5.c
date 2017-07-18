#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x25"); 
  __asm volatile("ADD R1, R11, #0xa9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
