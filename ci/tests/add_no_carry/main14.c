#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x95"); 
  __asm volatile("ADD R1, R4, #0x3fe");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
