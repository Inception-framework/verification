#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x56"); 
  __asm volatile("mov R5,#0x04"); 
  __asm volatile("LSL R0, R9, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
