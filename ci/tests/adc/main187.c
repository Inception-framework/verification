#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xa7"); 
  __asm volatile("mov R5,#0x0c"); 
  __asm volatile("ADCS R12, R0, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
