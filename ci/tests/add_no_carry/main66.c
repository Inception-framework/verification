#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x3b"); 
  __asm volatile("mov R4,#0x44"); 
  __asm volatile("ADD R4, R7, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
