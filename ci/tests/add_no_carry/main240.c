#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xf5"); 
  __asm volatile("ADD R3, R5, #0x92");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
