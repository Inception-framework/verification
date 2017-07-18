#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x0f"); 
  __asm volatile("mov R5,#0xb2"); 
  __asm volatile("ADD R5, R11, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
