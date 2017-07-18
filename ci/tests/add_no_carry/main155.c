#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x25"); 
  __asm volatile("ADD R6, R1, #0x43");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
