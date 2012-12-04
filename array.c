/*固定大小的多维数组优化示例*/
 #define N 16
 typedef int fix_matrix[N][N];
 /* Compute i,k of fixed matrix product */
 int fix_prod_ele (fix_matrix A, fix_matrix B, int i, int k)
 {
 	int j;
 	int result = 0;
 	
 	for (j = 0; j < N; j++)
 	{
 		result += A[i][j] * B[j][k];
 	}
 	return result;
 }
 
 /*编译器进行优化后的代码：*/
 /*Compute i, k of fixed matrix product */
 int fix_prod_ele_opt(fix_matrix A, fix_matrix B, int i, int k)
 {
 	int *Aptr = &A[i][0];
 	int *Bptr = &B[0][k];
    int cnt = N-1;
    int result = 0;
    
    do
    {
    	result += (*Aptr) * (*Bptr);
    	Aptr += 1;
    	Bptr += N;
    	cnt--;
    } while (cnt >= 0);
    
    return result;
}



/*可变大小数组的代码示例*/

typedef int *var_matrix;
/*Compute i,k of variable matrix product */
int var_prod_ele(var_matrix A, var_matrix B, int i, int k, int n)
{
	int j;
	int result = 0;
	
	for (j = 0; j < n; j++)
	{
		result += A[i*n + j] * B[j*n + k]
	}
	
	return result;
}

/*经过编译器优化过的代码*/
/*Compute i,k of variable matrix product */

int var_prod_ele_opt(var_matrix A, var_matrix B, int i, int k, int n)
{
	int *Aptr = &A[i*n];
	int nTjPK = n;
	int cnt = n;
	int result = 0;
	
	if (n <= 0)
	{
		return result;
	}
	
	do {
		result += (*Aptr) * B[nTjPK];
		Aptr += 1;
		nTjPK += n;
		cnt--;
	} while (cnt);
	
	return result;
}

	

#include <stdio.h>

int decimal5(int *);
int main()
{
	NULL;
    return 0;
}

int decimal5(int *x)
{
	int i;
	int val = 0;
	
	for (i = 0; i < 5; i++)
	{
		val = (10 * val ) + x[i];
	}
	
	return val;
}

/*所产生的相应汇编代码*/
	.file	"array.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$0, %eax
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	decimal5
	.type	decimal5, @function
decimal5:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	movl	$0, -8(%ebp)
	jmp	.L3
.L4:
	movl	-4(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movl	-8(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	addl	$1, -8(%ebp)
.L3:
	cmpl	$4, -8(%ebp)
	jle	.L4
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	decimal5, .-decimal5
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
