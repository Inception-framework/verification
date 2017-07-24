#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x64"); 
  __asm volatile("mov R9,#0x05"); 
  __asm volatile("LSL R12, R10, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
