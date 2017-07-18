#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xd5"); 
  __asm volatile("mov R11,#0x48"); 
  __asm volatile("ADD R6, R4, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
