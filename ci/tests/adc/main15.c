#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x5f"); 
  __asm volatile("mov R0,#0x85"); 
  __asm volatile("ADCS R2, R3, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
