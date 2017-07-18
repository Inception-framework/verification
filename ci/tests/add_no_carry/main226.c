#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xd3"); 
  __asm volatile("mov R3,#0xe1"); 
  __asm volatile("ADD R12, R2, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
