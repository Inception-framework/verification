#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x3f"); 
  __asm volatile("ADD R3, R10, #0x03a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
