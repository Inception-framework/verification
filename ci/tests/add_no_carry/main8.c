#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x85"); 
  __asm volatile("mov R0,#0x07"); 
  __asm volatile("ADDS R7, R8, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
