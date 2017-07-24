#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xfd"); 
  __asm volatile("LSR R2, R11, 4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
