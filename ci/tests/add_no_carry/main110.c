#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x27"); 
  __asm volatile("ADD R9, R1, #0xda");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
