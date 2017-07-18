#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x08"); 
  __asm volatile("ADD R3, R3, #0x8a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
