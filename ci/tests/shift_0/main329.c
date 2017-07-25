#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xb8"); 
  __asm volatile("mov R0,#0x04"); 
  __asm volatile("LSL R9, R5, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
