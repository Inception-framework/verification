#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xb7"); 
  __asm volatile("mov R3,#0x12"); 
  __asm volatile("LSL R11, R9, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
