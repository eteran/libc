
#ifndef SYSCALL_20110313_H_
#define SYSCALL_20110313_H_

namespace elibc {
#ifdef __i386__
	long syscall(unsigned long num) {
		long ret;
		__asm__ __volatile__("int $0x80" : "=a"(ret) : "a"(num) : "ecx");
		return ret;
	}

	template <class T1>
	long syscall(unsigned long num, T1 a1) {
		long ret;
		__asm__ __volatile__("int $0x80" : "=a"(ret) : "a"(num), "b"(a1) : "ecx");
		return ret;
	}

	template <class T1, class T2>
	long syscall(unsigned long num, T1 a1, T2 a2) {
		long ret;
		__asm__ __volatile__("int $0x80" : "=a"(ret) : "a"(num), "b"(a1), "c"(a2));
		return ret;
	}

	template <class T1, class T2, class T3>
	long syscall(unsigned long num, T1 a1, T2 a2, T3 a3) {
		long ret;
		__asm__ __volatile__("int $0x80" : "=a"(ret) : "a"(num), "b"(a1), "c"(a2), "d"(a3));
		return ret;
	}
#elif defined(__x86_64__)
	long syscall(unsigned long num) {
		long ret;
		__asm__ __volatile__("syscall" : "=a"(ret) : "a"(num) : "memory", "rcx", "r11");
		return ret;
	}

	template <class T1>
	long syscall(unsigned long num, T1 a1) {
		long ret;
		__asm__ __volatile__("syscall" : "=a"(ret) : "a"(num), "D"(a1) : "memory", "rcx", "r11");
		return ret;
	}

	template <class T1, class T2>
	long syscall(unsigned long num, T1 a1, T2 a2) {
		long ret;
		__asm__ __volatile__("syscall" : "=a"(ret) : "a"(num), "D"(a1), "S"(a2) : "memory", "rcx", "r11");
		return ret;
	}

	template <class T1, class T2, class T3>
	long syscall(unsigned long num, T1 a1, T2 a2, T3 a3) {
		long ret;
		__asm__ __volatile__("syscall" : "=a"(ret) : "a"(num), "D"(a1), "S"(a2), "d"(a3) : "memory", "rcx", "r11");
		return ret;
	}

	template <class T1, class T2, class T3, class T4>
	long syscall(unsigned long num, T1 a1, T2 a2, T3 a3, T4 a4) {
		long ret;
		register long r10 __asm__("r10") = a4;
		__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(num), "D"(a1), "S"(a2), "d"(a3), "r"(r10) : "memory", "rcx", "r11");
		return ret;
	}


	template <class T1, class T2, class T3, class T4, class T5>
	long syscall(unsigned long num, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
		unsigned long ret;
		register long r10 __asm__("r10") = a4;
		register long r8 __asm__("r8") = a5;
		__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(num), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8) : "memory", "rcx", "r11");
		return ret;
	}

	template <class T1, class T2, class T3, class T4, class T5, class T6>
	long syscall(unsigned long num, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) {
		unsigned long ret;
		register long r10 __asm__("r10") = a4;
		register long r8 __asm__("r8") = a5;
		register long r9 __asm__("r9") = a6;
		__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(num), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8), "r"(r9) : "memory", "rcx", "r11");
		return ret;
	}
#endif
}

#endif
