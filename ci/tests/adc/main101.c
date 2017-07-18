#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xe3"); 
  __asm volatile("ADCS R12, R6, #0xbe");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
