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
  __asm volatile("mov R4,sp"); 
  __asm volatile("mov R0,#0xb8"); 
  __asm volatile("mov R1,#0x58"); 
  __asm volatile("mov R2,#0x86"); 
  __asm volatile("mov R3,#0x0d"); 
  __asm volatile("mov R5,#0x8b"); 
  __asm volatile("mov R7,#0x54"); 
  __asm volatile("mov R9,#0x94"); 
  __asm volatile("mov R14,#0x2c"); 
  __asm volatile("STR R3, [R4]!");
  __asm volatile("mov R0,#0x8d"); 
  __asm volatile("mov R1,#0x36"); 
  __asm volatile("mov R2,#0x6d"); 
  __asm volatile("mov R3,#0x85"); 
  __asm volatile("mov R5,#0x63"); 
  __asm volatile("mov R7,#0x9e"); 
  __asm volatile("mov R9,#0xbe"); 
  __asm volatile("mov R14,#0xac"); 
  __asm volatile("LDR R3, [R4]!");
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
