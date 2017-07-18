#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xb7"); 
  __asm volatile("ADDS R1, R11, #0x75");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
