#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x8e"); 
  __asm volatile("ADDS R11, R12, #0x95");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
