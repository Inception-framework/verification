#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x7f"); 
  __asm volatile("LSL R11, R11, 21");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
