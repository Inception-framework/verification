#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x58"); 
  __asm volatile("mov R3,#0x98"); 
  __asm volatile("ADCS R11, R10, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
