#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x20"); 
  __asm volatile("ADD R2, R7, #0x84");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
