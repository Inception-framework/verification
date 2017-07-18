#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x58"); 
  __asm volatile("ADD R5, R0, #0x77");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
