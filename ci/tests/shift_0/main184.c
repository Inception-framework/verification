#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xef"); 
  __asm volatile("mov R2,#0x14"); 
  __asm volatile("LSR R6, R9, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
