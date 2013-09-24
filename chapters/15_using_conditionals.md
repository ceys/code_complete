#使用条件语句&控制循环

### if
* 首先写正常代码路径，再处理不常见情况。
* 当你有一个不包含else部分的if语句，除非其原因显而易见，否则请注释说明为什么这里else子句是没有必要的。
* 利用布尔函数简化复杂的检测。
* 对于if-then-else语句串，在最后else子句用出错信息或者断言来捕捉那些你不考虑的情况。

###选择循环的种类
* 预先不知道需要迭代多少次，使用while循环
* 如果把循环条件检测放在循环开始或结尾处，那就需要一个loop-and-a-half代码：
		score = 0;
		while (true) {
			GetNextRating(&ratingIncrement);
			rating = rating + ratingIncrement;

			if (!((score<targetScore) && (ratingIncrement!=0))) {
				break;
			}
		
			GetNextRating(&ratingIncrement);
			rating = rating + ratingIncrement;
		}

* 如果需要一个执行次数固定的循环，使用for。

###使用递归的技巧
* 确认递归能够停止
* 使用安全计数器防止出现无穷递归
* 把递归限制在一个子程序内
* 留心占空间：对于内存消耗大的对象，要用new在heap上创建对象，而不要让编译器在栈上自动创建对象
