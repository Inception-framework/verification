#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x0c"); 
  __asm volatile("LSL R4, R5, 14");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
