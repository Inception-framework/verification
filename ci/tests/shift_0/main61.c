#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x01"); 
  __asm volatile("mov R10,#0x06"); 
  __asm volatile("LSL R11, R12, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
