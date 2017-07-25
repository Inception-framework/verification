#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xfd"); 
  __asm volatile("mov R7,#0x05"); 
  __asm volatile("LSL R7, R12, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
