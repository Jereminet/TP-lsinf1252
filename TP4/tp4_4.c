int main(){
	int a=5;
	int b;
	if(a<=0){
		b=1;
	}else{
		b=0;
	}
}

    movl $5,%eax; //l pcq 32 bits
    movl %eax,a;

    compl $0,a;
    jg LBB4;    //g = greater
    movl $1,%ebx;
    jump END; //saut sans condition

LBB4:
    movl $0,%ebx;

END:
    movl %ebx,b;
