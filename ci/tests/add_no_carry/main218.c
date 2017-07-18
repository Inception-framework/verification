#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x29"); 
  __asm volatile("mov R3,#0xb1"); 
  __asm volatile("ADDS R3, R5, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
