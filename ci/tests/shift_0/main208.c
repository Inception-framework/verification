#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x58"); 
  __asm volatile("LSL R10, R10, 14");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
