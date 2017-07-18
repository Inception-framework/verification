#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x67"); 
  __asm volatile("mov R8,#0x70"); 
  __asm volatile("ADD R7, R10, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
