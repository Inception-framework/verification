#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xc4"); 
  __asm volatile("mov R4,#0x1e"); 
  __asm volatile("LSL R4, R8, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
