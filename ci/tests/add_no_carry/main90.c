#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x6f"); 
  __asm volatile("ADD R7, R12, #0xd8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
