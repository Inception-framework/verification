#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xcf"); 
  __asm volatile("mov R5,#0x12"); 
  __asm volatile("LSR R11, R12, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
