#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x2a"); 
  __asm volatile("ADD R8, R10, #0x42");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
