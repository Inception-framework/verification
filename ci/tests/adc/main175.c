#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xe1"); 
  __asm volatile("mov R9,#0x27"); 
  __asm volatile("ADCS R6, R3, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
