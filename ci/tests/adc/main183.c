#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x8b"); 
  __asm volatile("mov R1,#0xb7"); 
  __asm volatile("ADCS R1, R6, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
