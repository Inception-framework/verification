#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xda"); 
  __asm volatile("ADDS R9, R1, #0xc9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
