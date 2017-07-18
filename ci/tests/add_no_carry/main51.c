#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x62"); 
  __asm volatile("mov R11,#0xab"); 
  __asm volatile("ADD R0, R9, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
