#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xa1"); 
  __asm volatile("mov R8,#0x0f"); 
  __asm volatile("LSL R12, R3, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
