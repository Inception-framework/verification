#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xaf"); 
  __asm volatile("mov R1,#0xf5"); 
  __asm volatile("ADDS R5, R12, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
