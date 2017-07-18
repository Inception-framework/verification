#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xc3"); 
  __asm volatile("ADD R5, R8, #0x113");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
