#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0xf3"); 
  __asm volatile("ADD R7, R4, #0x6e4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
