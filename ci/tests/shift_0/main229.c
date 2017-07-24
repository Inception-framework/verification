#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x85"); 
  __asm volatile("mov R4,#0x0e"); 
  __asm volatile("LSL R8, R10, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
