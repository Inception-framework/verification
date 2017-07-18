#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x6e"); 
  __asm volatile("mov R9,#0x4a"); 
  __asm volatile("ADD R10, R0, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
