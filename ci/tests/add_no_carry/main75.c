#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x2f"); 
  __asm volatile("ADD R12, R5, #0xad");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
