#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x22"); 
  __asm volatile("ADD R12, R2, #0xd46");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
