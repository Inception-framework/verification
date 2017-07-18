#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x19"); 
  __asm volatile("mov R6,#0x11"); 
  __asm volatile("ADDS R7, R3, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
