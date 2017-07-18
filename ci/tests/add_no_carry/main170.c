#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x9a"); 
  __asm volatile("ADD R12, R10, #0x4f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
