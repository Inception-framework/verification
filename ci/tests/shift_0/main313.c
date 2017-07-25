#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x51"); 
  __asm volatile("mov R10,#0x0c"); 
  __asm volatile("LSL R0, R5, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
