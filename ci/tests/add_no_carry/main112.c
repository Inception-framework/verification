#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xc6"); 
  __asm volatile("ADDS R7, R12, #0x77");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
