
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
		__asm__ __volatile__("syscall" : "=a"(ret) : "a"(num) : "rcx");
		return ret;
	}

	template <class T1>
	long syscall(unsigned long num, T1 a1) {
		long ret;
		__asm__ __volatile__("syscall" : "=a"(ret) : "a"(num), "D"(a1) : "rcx");
		return ret;
	}

	template <class T1, class T2>
	long syscall(unsigned long num, T1 a1, T2 a2) {
		long ret;
		__asm__ __volatile__("syscall" : "=a"(ret) : "a"(num), "D"(a1), "S"(a2) : "rcx");
		return ret;
	}

	template <class T1, class T2, class T3>
	long syscall(unsigned long num, T1 a1, T2 a2, T3 a3) {
		long ret;
		__asm__ __volatile__("syscall" : "=a"(ret) : "a"(num), "D"(a1), "S"(a2), "d"(a3) : "rcx");
		return ret;
	}
#endif
}

#endif
