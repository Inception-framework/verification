#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0"); 
  __asm volatile("add R6,R6,#0x37"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0xcf"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0x80"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0x25"); 
  __asm volatile("SUB R11, R6, #0xfa");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}