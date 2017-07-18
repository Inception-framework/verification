#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xc4"); 
  __asm volatile("ADDS R3, R12, #0xb4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
