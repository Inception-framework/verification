#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xf8"); 
  __asm volatile("mov R6,#0x9b"); 
  __asm volatile("ADD R4, R8, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
