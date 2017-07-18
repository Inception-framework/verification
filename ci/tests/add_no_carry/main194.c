#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x95"); 
  __asm volatile("ADD R4, R10, #0x741");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
