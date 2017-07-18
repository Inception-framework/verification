#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xa3"); 
  __asm volatile("mov R8,#0xfa"); 
  __asm volatile("ADCS R1, R1, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
