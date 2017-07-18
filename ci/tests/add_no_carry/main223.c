#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xe0"); 
  __asm volatile("mov R0,#0xd3"); 
  __asm volatile("ADDS R7, R11, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
