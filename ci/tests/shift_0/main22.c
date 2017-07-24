#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xd6"); 
  __asm volatile("mov R9,#0x12"); 
  __asm volatile("LSR R10, R9, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
