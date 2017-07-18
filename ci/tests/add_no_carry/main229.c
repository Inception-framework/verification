#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xb4"); 
  __asm volatile("ADD R2, R4, #0xa3a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
