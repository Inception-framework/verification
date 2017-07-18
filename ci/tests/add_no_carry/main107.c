#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xe5"); 
  __asm volatile("ADDS R0, R12, #0xa9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
