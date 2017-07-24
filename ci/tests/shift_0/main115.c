#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x41"); 
  __asm volatile("mov R3,#0x12"); 
  __asm volatile("LSL R2, R10, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
