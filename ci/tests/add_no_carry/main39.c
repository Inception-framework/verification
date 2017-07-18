#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x68"); 
  __asm volatile("ADD R9, R2, #0x1db");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
