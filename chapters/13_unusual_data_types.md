# 不常见的数据类型

###结构体
* 用结构体来明确数据关系：把相关联的一组数据聚集在一起
* 用结构体简化对数据块的操作
* 用结构体简化参数列表
* 用结构体来减少维护

###指针
* 指针包含两部分内容：内存中的位置，如何解释指针所指的内容
* 把指针操作限制在子程序或者类里边：减少访问指针代码位置的数量。
* 同时声明和定义指针：`Employee * emplyeePtr = new Employee`
* 在与指针分配相同的作用域删除指针。
* 在使用指针之前检查指针
* 先检查指针所引用的变量再使用它
* 利用tag field来检测损毁的内存：tag field是指加入结构体内的一个仅仅用于检测错误的字段。在分配一个变量的时候，
把一个应该保持不变的值放在它的标记字段里。当你使用该结构时，特别是当你释放其内存时，检测这个标记字段的取值。
如果这个标记字段的取值与预期不符，那么这一数据就遭到破坏了。
* 用额外的指针变量来提高代码清晰度：
		//传统的插入节点的代码
		void InsertLink (
			Node *currentNode,
			Node *insertNode
			) {
			insertNode->next = currentNode->next;
			insertNode->previous = currentNode;
			if ( currentNode->next != NULL ) {
				currentNode->next->previous = insertNode;
			}
			currentNode->next = insertNode;
		}

		//更具可读性的节点插入代码
		void InsertLink ( Node *startNode, Node *newMiddleNode ) {
			Node *followingNode = startNode->next;
			newMiddleNode->next = folowingNode;
			newMiddleNode->previous = startNode;
			if ( followingNode != NULL ) {
				followingNode->previous = newMiddleNode;
			}
			startNode->next = newMiddleNode;
		}
* 简化复杂的指针表达式
* 画一个图，来解释指针链接关系
* 按照正确的顺序删除链表中的指针
* 分配一片保留的内存后备区域，一旦用光了内存，就释放保留下来的这片后备区，保存所做的工作并执行清理工作。
* 粉碎垃圾数据，在释放内存前用垃圾数据覆盖这些内存区域，并把指针设为空值，并在删除变量之前检查非法指针：
		ASSERT( pointer != NULL, "Attempting to delete null pointer." );
		memset( pointer, GARBAGE_DATA, MemoryBlockSize(pointer) ); 
		delete pointer;
		pointer = NULL;
* 耿总指针分配情况：维护一份已经分配的指针的列表。这样就能让你在释放一个指针之前检查它是不是位于列表里面。
* 编写覆盖子程序，几种实现避免指针问题的策略：
SAFE_NEW：这个子程序用new来分配指针，把这一新的指针加入已分配指针列表，然后将这一新分配的指针返回给调用方子程序，检查new操作的返回值是否为空或是否抛出异常。

###全局数据：用访问器子程序取代全局数据
* 要求所有代码通过访问器子程序来存取数据。
* 不要把全局数据扔在一处：考虑每一个全局数据属于哪个类。
* 用锁定来控制对全局变量的访问，支持并发。
