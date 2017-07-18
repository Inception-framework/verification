#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x06"); 
  __asm volatile("ADD R8, R11, #0xea");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
