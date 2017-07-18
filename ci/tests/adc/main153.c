#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xde"); 
  __asm volatile("ADCS R5, R6, #0x4b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
