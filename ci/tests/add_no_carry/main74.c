#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xaa"); 
  __asm volatile("ADD R2, R4, #0xacc");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
