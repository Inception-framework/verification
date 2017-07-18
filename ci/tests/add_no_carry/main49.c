#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x43"); 
  __asm volatile("ADD R10, R5, #0x9ed");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
