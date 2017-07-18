#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xc4"); 
  __asm volatile("mov R10,#0x8b"); 
  __asm volatile("ADD R0, R1, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
