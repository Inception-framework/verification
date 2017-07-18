#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xb3"); 
  __asm volatile("mov R0,#0x94"); 
  __asm volatile("ADD R0, R2, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
