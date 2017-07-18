#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x64"); 
  __asm volatile("mov R9,#0x2b"); 
  __asm volatile("ADD R4, R12, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
