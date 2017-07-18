#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x7a"); 
  __asm volatile("mov R0,#0x9c"); 
  __asm volatile("ADD R7, R5, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
