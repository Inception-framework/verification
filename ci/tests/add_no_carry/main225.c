#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x7b"); 
  __asm volatile("ADD R1, R1, #0x32");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
