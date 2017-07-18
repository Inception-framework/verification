#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x6e"); 
  __asm volatile("mov R3,#0x2f"); 
  __asm volatile("ADCS R4, R0, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
