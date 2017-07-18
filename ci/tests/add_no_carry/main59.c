#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xd4"); 
  __asm volatile("ADD R12, R12, #0x604");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
