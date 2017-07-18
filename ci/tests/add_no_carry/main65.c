#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x29"); 
  __asm volatile("ADD R6, R10, #0x0b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
