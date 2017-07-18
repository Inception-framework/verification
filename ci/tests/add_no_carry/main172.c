#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xcf"); 
  __asm volatile("ADDS R12, R3, #0x8f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
