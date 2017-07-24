#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x18"); 
  __asm volatile("LSL R6, R7, 6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
