#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x96"); 
  __asm volatile("LSL R6, R9, 30");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
