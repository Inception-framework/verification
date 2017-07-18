#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xa1"); 
  __asm volatile("ADD R11, R2, #0x422");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
