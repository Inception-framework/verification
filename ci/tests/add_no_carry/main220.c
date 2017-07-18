#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xc4"); 
  __asm volatile("ADD R4, R8, #0x82");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
