#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x2b"); 
  __asm volatile("mov R8,#0x02"); 
  __asm volatile("LSL R1, R12, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
