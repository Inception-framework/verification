#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x43"); 
  __asm volatile("ADD R10, R0, #0x0a8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
