#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x54"); 
  __asm volatile("ROR R11, R0, 15");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
