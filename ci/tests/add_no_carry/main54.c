#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xd6"); 
  __asm volatile("ADD R11, R9, #0x17f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
