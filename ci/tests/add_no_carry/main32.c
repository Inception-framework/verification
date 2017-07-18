#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xf5"); 
  __asm volatile("ADDS R11, R1, #0x6b");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
