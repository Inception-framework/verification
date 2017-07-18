#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x01"); 
  __asm volatile("ADDS R3, R0, #0x32");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
