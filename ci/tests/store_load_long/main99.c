#include <stdlib.h>
int STACK[2050];__attribute__((naked))
void foo(void){
  #ifndef KLEE
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("add r1,r1,#1025");
  __asm volatile("mov r2,sp");
  __asm volatile("loop:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  __asm volatile("add r2,#1025");
  __asm volatile("lsl r2,#2");
  __asm volatile("add r2,sp");
  __asm volatile("loop2:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop2");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  #endif
  __asm volatile("mov R9,sp"); 
  __asm volatile("mov R0,#0x4d"); 
  __asm volatile("mov R1,#0x4d"); 
  __asm volatile("mov R3,#0x07"); 
  __asm volatile("mov R4,#0x51"); 
  __asm volatile("mov R6,#0x9a"); 
  __asm volatile("mov R7,#0x89"); 
  __asm volatile("mov R8,#0xc6"); 
  __asm volatile("mov R10,#0xca"); 
  __asm volatile("mov R11,#0x44"); 
  __asm volatile("mov R12,#0x31"); 
  __asm volatile("STRH R3, [R9]!");
  __asm volatile("mov R0,#0x76"); 
  __asm volatile("mov R1,#0xc7"); 
  __asm volatile("mov R3,#0x20"); 
  __asm volatile("mov R4,#0x15"); 
  __asm volatile("mov R6,#0x0f"); 
  __asm volatile("mov R7,#0xf2"); 
  __asm volatile("mov R8,#0xda"); 
  __asm volatile("mov R10,#0xe3"); 
  __asm volatile("mov R11,#0xbb"); 
  __asm volatile("mov R12,#0x12"); 
  __asm volatile("LDRH R3, [R9]!");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
void main(void){
  int i;  for(i=0;i<2050;i++){
      STACK[2050-1-i]=i;
  }
  foo();
}
