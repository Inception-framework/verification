#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x15"); 
  __asm volatile("ADD R5, R9, #0xfd");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
