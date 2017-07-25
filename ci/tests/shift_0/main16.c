#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x68"); 
  __asm volatile("LSL R5, R8, 18");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
