#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x42"); 
  __asm volatile("ADD R1, R10, #0x4c9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
