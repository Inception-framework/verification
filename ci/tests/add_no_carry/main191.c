#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x05"); 
  __asm volatile("mov R8,#0x22"); 
  __asm volatile("ADD R7, R6, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
