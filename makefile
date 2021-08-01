Trees: BinaryTreeTests.o MemoryList.o BinaryTree.o CharMatrix.o
	clang -o Tree BinaryTreeTests.o MemoryList.o BinaryTree.o CharMatrix.o
	rm -f *.o

BinaryTreeTests.o: tests/BinaryTreeTests.c gc/MemoryList.h BinaryTree/BinaryTree.h CharMatrix/CharMatrix.h
	clang -c tests/BinaryTreeTests.c

MemoryList.o: gc/MemoryList.c gc/MemoryList.h LinkedList/LinkedList.h
	clang -c gc/MemoryList.c

BinaryTree.o: BinaryTree/BinaryTree.c BinaryTree/BinaryTree.h gc/MemoryList.h CharMatrix/CharMatrix.h
	clang -c BinaryTree/BinaryTree.c

CharMatrix.o: CharMatrix/CharMatrix.c CharMatrix/CharMatrix.h gc/MemoryList.h
	clang -c CharMatrix/CharMatrix.c