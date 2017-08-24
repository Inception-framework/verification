static int global;
int y4;

typedef struct {
  int a;
  int b;
} my_type;

typedef struct {
  int a;
  int* b;
  char* c;
} my_subtype;

typedef struct {
  int a;
  char* b;
  //my_subtype mst;
  //char mario[5];
} mixed_type;



__attribute__((naked))
int fibonacci1(int n){
  __asm volatile("push	{r4, r7, lr}");
  __asm volatile("sub	sp, #12");
  __asm volatile("add	r7, sp, #0");
  __asm volatile("str	r0, [r7, #4]");
  __asm volatile("ldr	r3, [r7, #4]");
  __asm volatile("cmp	r3, #3");
  __asm volatile("bhs	continue");
  __asm volatile("movs	r3, #1");
  __asm volatile("b.n	stop");
  __asm volatile("continue:");
  __asm volatile("ldr	r3, [r7, #4]");
  __asm volatile("subs	r3, #1");
  __asm volatile("mov	r0, r3");
  __asm volatile("bl	fibonacci1");
  __asm volatile("mov	r4, r0");
  __asm volatile("ldr	r3, [r7, #4]");
  __asm volatile("subs	r3, #2");
  __asm volatile("mov	r0, r3");
  __asm volatile("bl	fibonacci1");
  __asm volatile("mov	r3, r0");
  __asm volatile("add	r3, r4");
  __asm volatile("stop:");
  __asm volatile("mov	r0, r3");
  __asm volatile("adds	r7, #12");
  __asm volatile("mov	sp, r7");
  __asm volatile("pop	{r4, r7, pc}");
}

int fibonacci2(int n){
  __asm volatile("mov r0,r0");
  if(n <= 2) return 1;
  return fibonacci2(n-1)+fibonacci2(n-2);
}

__attribute__((naked))
int fibonacci3(int n){
  __asm volatile("bl fibonacci2");
  __asm volatile("bx lr");
}

void fibonacci4(void){
  int y,x;
  __asm volatile("mov %[dest], %[value]" : [dest] "=r" (x) : [value] "r"(global)  );
  y = fibonacci_golden(x);
  __asm volatile("mov %[dest], %[value]" : [dest] "=r" (y4) : [value] "r"(y)  );
  __asm volatile("bx lr");
}

int fibonacci_golden(int n){
  if(n <= 2) return 1;
  return fibonacci_golden(n-1)+fibonacci_golden(n-2);
}

__attribute__((naked))
char inc_char(char a){
  __asm volatile("add r0,r0,#1");
  __asm volatile("bx lr");
}

char inc_char_golden(char a){
  return ++a;
}

my_type* inc_type(my_type* my_thing_ptr){
  __asm volatile("mov r0,r0");
  my_thing_ptr->a++;
  my_thing_ptr->b++;
  return my_thing_ptr;
}

my_type* inc_type_golden(my_type* my_thing_ptr){
  my_thing_ptr->a++;
  my_thing_ptr->b++;
  return my_thing_ptr;
}

mixed_type add_type1(mixed_type* mt_ptr){
  __asm volatile("mov r0,r0");
  mixed_type tmp;
  tmp.a = mt_ptr->a;
  tmp.b = mt_ptr->b;
  tmp.a++;
  *tmp.b = 'b';
  return tmp;
}

mixed_type add_type2(mixed_type mt){
  __asm volatile("mov r0,r0");
  mixed_type tmp;
  tmp.a = mt.a;
  tmp.b = mt.b;
  tmp.a++;
  *tmp.b = 'b';
  return tmp;
}

mixed_type add_type_golden(mixed_type* mt_ptr){
  mixed_type tmp;
  tmp.a = mt_ptr->a;
  tmp.b = mt_ptr->b;
  tmp.a++;
  *tmp.b = 'b';
  return tmp;
}


void main(void){
  int x,y1,y2,y3,y_golden;
  x = 6;
  y1 = fibonacci1(x);
  y2 = fibonacci2(x);
  y3 = fibonacci3(x);
  global = x;
  fibonacci4();
  y_golden = fibonacci_golden(x);

  int a = 'a';
  char b, b_golden;
  b_golden = inc_char_golden(a);
  b = inc_char(a);

  my_type my_thing;
  my_type my_thing_inc, my_thing_inc_golden;
  
  my_thing.a = 0;
  my_thing.b = 1;
  my_thing_inc = *inc_type(&my_thing);
  
  my_thing.a = 0;
  my_thing.b = 1;
  my_thing_inc_golden = *inc_type_golden(&my_thing);

  mixed_type mt;
  mixed_type mt1;
  mixed_type mt2;
  mixed_type mt_golden;
 
  mt.a = 0;
  char c = 'a';
  mt.b = &c;
  mt1 = add_type1(&mt);

  mt.a = 0;
  c = 'a';
  mt.b = &c;
  mt2 = add_type2(mt);

  mt.a = 0;
  c = 'a';
  mt.b = &c;
  mt_golden = add_type_golden(&mt);


  #ifndef NOPRINT
  printf("fibonacci1(%d) = %d\n",x,y1);
  printf("fibonacci2(%d) = %d\n",x,y2);
  printf("fibonacci3(%d) = %d\n",x,y3);
  printf("fibonacci4(%d) = %d\n",x,y4);
  printf("fibonacci_golden(%d) = %d\n",x,y_golden);
  if(y1 != y_golden){
    printf("error!! y1 != y_golden\n");
  }else{
    printf("ok!! y1 == y_golden\n");
  }
  if(y2 != y_golden){
    printf("error!! y2 != y_golden\n");
  }else{
    printf("ok!! y2 == y_golden\n");
  }
  if(y3 != y_golden){
    printf("error!! y3 != y_golden\n");
  }else{
    printf("ok!! y3 == y_golden\n");
  }
  if(y4 != y_golden){
    printf("error!! y4 != y_golden\n");
  }else{
    printf("ok!! y4 == y_golden\n");
  }

  printf("\n");

  printf("inc_char(%c) = %c\n",a,b);
  printf("inc_char_golden(%c) = %c\n",a,b_golden);
  if(b != b_golden){
    printf("error!! b != b_golden\n");
  }else{
    printf("ok!! b == b_golden\n");
  }

  printf("\n");
  
  printf("my_thing_inc .a .b = %d , %d\n",my_thing_inc.a,my_thing_inc.b);
  printf("my_thing_inc_golden .a,.b = %d,%d\n",my_thing_inc_golden.a,my_thing_inc_golden.b);
  if(my_thing_inc.a != my_thing_inc_golden.a || my_thing_inc.b != my_thing_inc_golden.b ){
    printf("error!! my_inc_thing != my_inc_thing_golden\n");
  }else{
    printf("ok!! my_inc_thing == my_inc_thing_golden\n");
  }

  printf("\n");
  
  printf("mt1 .a *.b = %d, %c\n",mt1.a,*mt1.b);
  printf("mt2 .a *.b = %d, %c\n",mt2.a,*mt2.b);
  printf("mt_golden .a *.b = %d, %c\n",mt_golden.a,*mt_golden.b);

  if(mt1.a != mt_golden.a || *mt.b != *mt_golden.b){
    printf("error!! mt1 != mt1_golden\n");
  }else{
    printf("ok!! mt1 == mt1_golden\n");
  } 
  if(mt2.a != mt_golden.a || *mt2.b != *mt_golden.b){
    printf("error!! mt2 != mt2_golden\n");
  }else{
    printf("ok!! mt2 == mt2_golden\n");
  } 
 
  #endif
}
