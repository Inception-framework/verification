#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x70"); 
  __asm volatile("mov R5,#0x57"); 
  __asm volatile("ADD R1, R11, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
