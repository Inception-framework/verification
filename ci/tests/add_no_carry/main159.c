#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x1d"); 
  __asm volatile("ADD R10, R8, #0xc0b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
