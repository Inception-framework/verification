#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x03"); 
  __asm volatile("ADD R3, R4, #0xdb");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
