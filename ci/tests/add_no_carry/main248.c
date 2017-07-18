#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x43"); 
  __asm volatile("mov R10,#0xff"); 
  __asm volatile("ADDS R9, R9, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
