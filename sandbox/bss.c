// common
// int a;
// .data
// int a = 1;

int	main()
{
	// stack
	// int a;
	// stack
	// int a = 2;
	// section .cstring
	char *a = "hello";
	// https://downloads.ti.com/docs/esd/SPRU513/c-strings-stdz0959975.html#STDZ0959975
	// section .cstring
	// .cstringは結局どこなのか
	// アセンブリを見ると、	.section	__TEXT,__cstring,cstring_literals とあるので.textセグメントなのだろうか
	// どうやらMachOの独自の型らしい。mach-o-x86-64
	// どうやら__TEXT == segment cstring = section textセグメント中の cstringセクションに存在するっぽい
	// char a[] = "hello";

	// stack
	// char a = 'a';

	//文字列だけ特別な領域に保存されている
	// 他に例外はあるのか
}
