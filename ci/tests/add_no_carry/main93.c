#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x0e"); 
  __asm volatile("mov R8,#0xe7"); 
  __asm volatile("ADDS R1, R11, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
