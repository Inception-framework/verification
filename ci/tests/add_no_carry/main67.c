#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xb1"); 
  __asm volatile("ADDS R10, R8, #0x3a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
