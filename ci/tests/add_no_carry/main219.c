#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x80"); 
  __asm volatile("ADD R3, R3, #0x9a4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
