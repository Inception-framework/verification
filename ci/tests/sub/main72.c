#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0"); 
  __asm volatile("add R6,R6,#0xd3"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0xb5"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0x64"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0xb0"); 
  __asm volatile("SUB R7, R6, #0x35");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
