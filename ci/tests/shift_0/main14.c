#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x3f"); 
  __asm volatile("LSR R8, R4, 22");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
