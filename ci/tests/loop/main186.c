#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9, #0"); 
  __asm volatile("loop:"); 
  __asm volatile("add R9,R9,#1"); 
  __asm volatile("cmp R9,#0x100"); 
  __asm volatile("bcc loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
