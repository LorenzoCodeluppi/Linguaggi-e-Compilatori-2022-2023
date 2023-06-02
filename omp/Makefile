CPPFLAGS = -I/usr/local/opt/llvm/include -fopenmp
LLVMFLAGS := $(shell llvm-config --ldflags --libs --system-libs)

omp_test: omp_test.c
	clang -O0 $(CPPFLAGS) ${LLVMFLAGS} $^ -o $@

clean:
	$(RM) omp_test

no_parallel:
	gcc -O0 omp_test.c -o omp_test