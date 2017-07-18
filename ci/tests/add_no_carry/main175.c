#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x81"); 
  __asm volatile("ADD R7, R1, #0xb5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
