#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x94"); 
  __asm volatile("mov R8,#0xd5"); 
  __asm volatile("ADD R12, R3, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
