# 程序说明 #
## 调试结果 ##
### 1. ###
按下第1次F10，并没有真正地执行什么程序，看到“局部变量”窗口中显示内存中变量的值，结果显示如下：

![](img/bug2.png)
### 2. ###
按下第2次F10，程序中变量的声明，执行的程序语句如下：

    int main() {
    	LinkList L;
    	ElemType e;
    	Status i;
    	int j, k;

可以看到调试窗口的输出结果如下:

![](img/bug3.png)
### 3. ###
按下第3次F10，程序中是给链表初始化，执行的程序语句如下：

	i = InitList(&L);

这个函数的原型如下所示，例举出来作为显示，更加直观地看到。

    /* Initial order linear table */
    Status InitList(LinkList *L) {
    	*L = (LinkList)malloc(sizeof(Node)); /* Generates a header node, and causes the L to point to the header node */
    	if (!(*L)) /* Memory allocation failure */
    		return ERROR;
    	(*L)->next = NULL; /* Pointer field is empty */
    
    	return OK;
    }
    

在“局部变量”窗口中显示的结果如下：

![](img/bug4.png)
### 4. ###
按下第4次F10，执行结果是返回没有被赋值的链表L的长度，执行的程序语句如下：

	printf("After initialization L:ListLength(L)=%d\n", ListLength(L));

注意一下，上面是一条语句，在“局部变量”窗口中显示的结果如下：

![](img/bug5.png)

### 5. ###
这里要按下几次F10，向链表L中插入数据，执行的程序语句如下：

	for (j = 1; j <= 5; j++)
		i = ListInsert(&L, 1, j);

这个函数的原型如下，便于自己查看和理解。

    /* Initial condition: sequential linear table L already exists,1≤i≤ListLength(L) */
    /* Operation results: insert the new data element E, L length plus 1 before the first I position in the L. */
    Status ListInsert(LinkList *L, int i, ElemType e) {
    	int j;
    	LinkList p, s;
    	p = *L;
    	j = 1;
    	while (p && j < i) { /* Find the i-th node */
    		p = p->next;
    		++j;
    	}
    	if (!p || j>i)
    		return ERROR; /* The i-th element is not exist*/
    	s = (LinkList)malloc(sizeof(Node)); /* Create new node (C language standard function) */
    	s->data = e;
    	s->next = p->next;	/* Assign the successor node of p to the successor of s */
    	p->next = s; /* Assign s to the successor to p */
    	return OK;
    }

插入第一个数据的“局部变量”窗口中显示的结果如下所示:

![](img/bug6.png)

等所有的数据元素插入完成之后，显示的”局部变量“窗口中的信息如下：（总共插入了6个数据，我是数了“data”的个数）

![](img/bug7.png)

### 6. ###
按下1次F10，执行的程序语句如下：

	ListTraverse(L);

这个函数的原型如下所示：

    /* Initial condition: sequential linear table L already exists */
    /* Operation results: the output of each data element in L in turn */
    Status ListTraverse(LinkList L) {
    	LinkList p = L->next;
    	while (p) {
    		visit(p->data);
    		p = p->next;
    	}
    	printf("\n");
    	return OK;
    }

在“局部变量”窗口中没有什么明显变化，可以看到在CMD窗口中输出提示信息：

![](img/bug8.png)

### 7. ###
跳过非关键步骤，有个关键的程序语句，代码如下：

	i = ListEmpty(L);

上面语句的执行是判断链表L是否为空的，执行后在“局部变量”窗口中查看到的提示信息如下：

![](img/bug9.png)

同时，在CMD窗口中输出结果如下：

![](img/bug10.png)

### 8. ###
按下F10调试，执行的程序语句如下：

	i = ClearList(&L);

这个语句的作用是清空链表L的，可以看到“局部变量”窗口中明显的变化，如下：

![](img/bug11.png)

### 9. ###
这里再跳过一些非关键的步骤，直接到下面的程序语句的执行，程序代码如下：

	for (j = 1; j <= 10; j++)
		ListInsert(&L, j, j);

插入11个数据(你可以数data的数量，你就知道是11个元素了)到目前为空的链表L中，多次单步跨过程执行之后，最终在“局部变量”窗口中输出的提示信息如下：

![](img/bug12.png)

### 10. ###
跳过一些F10步骤，直接到下面的程序语句的执行，代码如下：

	ListInsert(&L, 1, 0);

这个语句的作用是在链表L的第1个位置插入元素0，可以明显在“局部变量”窗口中看到提示信息（我在这里用的是非16进制显示，目的便于看清楚）,补充一句，由于插入一个元素，可以知道链表L的长度增加了1位。

![](img/bug13.png)

### 11. ###
跳过一些F10步骤，直接到下面的程序语句的执行，代码如下：

	GetElem(L, 5, &e);

程序的作用是：

    /* Initial condition: sequential linear table L already exists,1≤i≤ListLength(L) */
    /* Operation result: returns the value of the first I data element in L with e */
    Status GetElem(LinkList L, int i, ElemType *e) {
    	int j;
    	LinkList p; /* Declare a node p */
    	p = L->next; /* Let p point to the first node of the LinkList L */
    	j = 1; /* j as a counter */
    	while (p && j < i) {
    		p = p->next; /* when p is not empty or counter j is not equal to i,the cycle continues */
    		++j;
    	}
    	if (!p || j>i)
    		return ERROR; /* The i element does not exist */
    	*e = p->data; /* Take the i-th element data */
    	return OK;
    }

我想程序至此终结，没什么新意了。

## 总结 ##
### 1 ###
2016/7/19 11:24:54-输入程序的第一遍，没有明显的错误，有一个Warning在网络上找到解答了，就解决了。但是按下F10键，想看看内存中数据中的存储方式，输出这个的结果，留待后来解决：
![](img/bug1.png)

>2016/8/2 8:55:44 我现在才明白，上面的“局部变量”显示的结果没有错误，本来就是这样的，不是出现了错误。



