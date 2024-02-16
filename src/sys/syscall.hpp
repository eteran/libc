
#ifndef SYSCALL_20110313_HPP_
#define SYSCALL_20110313_HPP_

namespace elibc {
#if defined(__x86_64__)
inline long syscall(long num) {
	long ret;
	register long n __asm__("rax") = (num);

	__asm__ volatile(
		"syscall\n"
		: "=a"(ret)
		: "0"(n)
		: "rcx", "r11", "memory", "cc");
	return ret;
}

template <class T1>
long syscall(long num, T1 a1) {
	long ret;
	register long n __asm__("rax")  = (num);
	register long r1 __asm__("rdi") = (long)(a1);

	__asm__ volatile(
		"syscall\n"
		: "=a"(ret)
		: "r"(r1),
		  "0"(n)
		: "rcx", "r11", "memory", "cc");
	return ret;
}

template <class T1, class T2>
long syscall(long num, T1 a1, T2 a2) {
	long ret;
	register long n __asm__("rax")  = (num);
	register long r1 __asm__("rdi") = (long)(a1);
	register long r2 __asm__("rsi") = (long)(a2);

	__asm__ volatile(
		"syscall\n"
		: "=a"(ret)
		: "r"(r1), "r"(r2),
		  "0"(n)
		: "rcx", "r11", "memory", "cc");
	return ret;
}

template <class T1, class T2, class T3>
long syscall(long num, T1 a1, T2 a2, T3 a3) {
	long ret;
	register long n __asm__("rax")  = (num);
	register long r1 __asm__("rdi") = (long)(a1);
	register long r2 __asm__("rsi") = (long)(a2);
	register long r3 __asm__("rdx") = (long)(a3);

	__asm__ volatile(
		"syscall\n"
		: "=a"(ret)
		: "r"(r1), "r"(r2), "r"(r3),
		  "0"(n)
		: "rcx", "r11", "memory", "cc");
	return ret;
}

template <class T1, class T2, class T3, class T4>
long syscall(long num, T1 a1, T2 a2, T3 a3, T4 a4) {
	long ret;
	register long n __asm__("rax")  = (num);
	register long r1 __asm__("rdi") = (long)(a1);
	register long r2 __asm__("rsi") = (long)(a2);
	register long r3 __asm__("rdx") = (long)(a3);
	register long r4 __asm__("r10") = (long)(a4);

	__asm__ volatile(
		"syscall\n"
		: "=a"(ret)
		: "r"(r1), "r"(r2), "r"(r3), "r"(r4),
		  "0"(n)
		: "rcx", "r11", "memory", "cc");
	return ret;
}

template <class T1, class T2, class T3, class T4, class T5>
long syscall(long num, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
	long ret;
	register long n __asm__("rax")  = (num);
	register long r1 __asm__("rdi") = (long)(a1);
	register long r2 __asm__("rsi") = (long)(a2);
	register long r3 __asm__("rdx") = (long)(a3);
	register long r4 __asm__("r10") = (long)(a4);
	register long r5 __asm__("r8")  = (long)(a5);

	__asm__ volatile(
		"syscall\n"
		: "=a"(ret)
		: "r"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5),
		  "0"(n)
		: "rcx", "r11", "memory", "cc");
	return ret;
}

template <class T1, class T2, class T3, class T4, class T5, class T6>
long syscall(long num, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) {
	long ret;
	register long n __asm__("rax")  = (num);
	register long r1 __asm__("rdi") = (long)(a1);
	register long r2 __asm__("rsi") = (long)(a2);
	register long r3 __asm__("rdx") = (long)(a3);
	register long r4 __asm__("r10") = (long)(a4);
	register long r5 __asm__("r8")  = (long)(a5);
	register long r6 __asm__("r9")  = (long)(a6);

	__asm__ volatile(
		"syscall\n"
		: "=a"(ret)
		: "r"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5), "r"(r6), "0"(n)
		: "rcx", "r11", "memory", "cc");
	return ret;
}
#endif
}

#endif
