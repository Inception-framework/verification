#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x82"); 
  __asm volatile("mov R0,#0x6e"); 
  __asm volatile("ADDS R0, R7, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
