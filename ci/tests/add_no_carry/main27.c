#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x1f"); 
  __asm volatile("ADDS R5, R6, #0x33");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
