# 运行结果 #
![](img/result.png)

# 调试信息 #
## 1. ##
按下F10，在程序还没有申明变量之前，编辑器为程序中的变量分配的内存情况，在“局部变量”窗口中反馈如下：

![](img/img1.png)



# 总结 #
## 1. ##
首先第一点，就是画出二叉树的结构图，才能更好地去理解程序。采用的是二叉树的链式存储结果（这个二叉树的概念的理解，我是从王道考研数据结构书上看到的）

![](img/nb1.png)

分析“局部变量”窗口中的内存信息，可以得到二叉树的结构如下：

![](img/nb2.png)

可以用上面的前序、中序、后序遍历序列，来验证所得到的图，是否正确。

这个二叉树的生成语句如下：

	StrAssign(str, "ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);

由上面的字母序列：ABDH#K###E##CFI###G#J##，可知大约是按照前序的序列生成的二叉树。

函数的原型如下：（清晰明了）

    /* 按前序输入二叉树中结点的值（一个字符） */
    /* #表示空树，构造二叉链表表示二叉树T。 */
    void CreateBiTree(BiTree *T) {
    	TElemType ch;
    
    	/* scanf("%c",&ch); */
    	ch = str[index++];
    
    	if (ch == '#')
    		*T = NULL;
    	else {
    		*T = (BiTree)malloc(sizeof(BiTNode));
    		if (!*T)
    			exit(OVERFLOW);
    		(*T)->data = ch; /* 生成根结点 */
    		CreateBiTree(&(*T)->lchild); /* 构造左子树 */
    		CreateBiTree(&(*T)->rchild); /* 构造右子树 */
    	}
    }

## 2. ##
补充一点，如何销毁一颗链式存储结构的二叉树，函数原型如下：

    /* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
    void DestroyBiTree(BiTree *T) {
    	if (*T) {
    		if ((*T)->lchild) /* 有左孩子 */
    			DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
    		if ((*T)->rchild) /* 有右孩子 */
    			DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
    		free(*T); /* 释放根结点 */
    		*T = NULL; /* 空指针赋0 */
    	}
    }

在源程序中，用了另外的一个名称宏定义销毁二叉树的函数名

    #define ClearBiTree DestroyBiTree

>在C语言中，malloc是根据量动态地建立结点，free是根据量动态地释放结点。





















