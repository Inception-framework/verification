#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xe3"); 
  __asm volatile("ADD R3, R2, #0xb2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
