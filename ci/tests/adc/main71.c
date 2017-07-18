#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xbc"); 
  __asm volatile("mov R3,#0x85"); 
  __asm volatile("ADCS R6, R1, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
