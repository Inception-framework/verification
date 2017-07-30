#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11, #100"); 
  __asm volatile("loop:"); 
  __asm volatile("add R11,R11,#-1"); 
  __asm volatile("cmp R11,#0"); 
  __asm volatile("bcc loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
