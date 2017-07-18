#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x1f"); 
  __asm volatile("mov R6,#0x04"); 
  __asm volatile("ADDS R11, R3, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
