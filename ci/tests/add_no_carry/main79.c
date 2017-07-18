#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x7a"); 
  __asm volatile("ADD R7, R11, #0x18b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
