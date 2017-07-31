#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0"); 
  __asm volatile("add R10,R10,#0xe9"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xbb"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x17"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xbc"); 
  __asm volatile("SUB R9, R10, #0xf4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
