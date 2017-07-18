#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x48"); 
  __asm volatile("ADDS R3, R12, #0xe5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
