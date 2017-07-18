#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x7c"); 
  __asm volatile("ADDS R5, R8, #0x79");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
