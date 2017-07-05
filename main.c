#include <stdlib.h>
__attribute__((naked))
void main(void){
  // set input registers
  __asm volatile("mov r0,#5");
  // instruction under test
  __asm volatile("mov r3,r0");
  while(1);
}
