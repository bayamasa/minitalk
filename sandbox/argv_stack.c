#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	// アセンブリを見るとわかる通り、argc/argvはスタック領域に格納される
	// ; int size分 スタックを取る
	// movl	%edi, -4(%rbp)
	// ; ポインタ分 sizeを取る
	// movq	%rsi, -16(%rbp)

	write(1, argv[1], 1);
}
