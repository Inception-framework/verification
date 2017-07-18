#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x4b"); 
  __asm volatile("ADD R8, R11, #0x9ec");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
