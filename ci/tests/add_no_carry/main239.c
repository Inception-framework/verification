#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x9d"); 
  __asm volatile("ADD R1, R8, #0xa79");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
