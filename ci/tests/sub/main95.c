#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0"); 
  __asm volatile("add R12,R12,#0xa1"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xcb"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xa1"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x82"); 
  __asm volatile("SUB R5, R12, #0x16d");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
