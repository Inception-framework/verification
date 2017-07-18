#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xab"); 
  __asm volatile("mov R0,#0x12"); 
  __asm volatile("ADDS R4, R11, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
