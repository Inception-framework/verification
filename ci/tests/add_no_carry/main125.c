#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xb1"); 
  __asm volatile("ADD R1, R11, #0x63");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
