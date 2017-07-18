#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x15"); 
  __asm volatile("ADD R5, R4, #0x16");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
