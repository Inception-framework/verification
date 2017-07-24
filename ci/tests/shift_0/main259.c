#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xd8"); 
  __asm volatile("mov R2,#0x0d"); 
  __asm volatile("LSL R5, R10, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
