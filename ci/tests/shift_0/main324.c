#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xc7"); 
  __asm volatile("mov R11,#0x03"); 
  __asm volatile("LSR R12, R10, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
