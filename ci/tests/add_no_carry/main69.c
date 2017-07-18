#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x84"); 
  __asm volatile("ADD R3, R10, #0xa12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
