#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xd5"); 
  __asm volatile("mov R7,#0x18"); 
  __asm volatile("LSL R8, R9, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
