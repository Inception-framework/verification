#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x78"); 
  __asm volatile("ASR R8, R12, 14");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
