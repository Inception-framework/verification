#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xe3"); 
  __asm volatile("mov R5,#0x61"); 
  __asm volatile("ADD R12, R6, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
