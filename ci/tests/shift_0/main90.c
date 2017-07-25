#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x6f"); 
  __asm volatile("LSR R12, R9, 28");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
