#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x65"); 
  __asm volatile("LSL R9, R10, 19");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
