# 运行结果

运行结果在一个屏幕下面都看不完，下面是最主要部分的CMD调试结果，如下图所示：

![](img/result.png)

# 调试信息

## 1.

按下1次F10，编辑器在程序中的变量还未申明之前，就事先在内存中开辟了变量空间，在“局部变量”窗口中查看的结果如下：

![](img/img1.png)

## 2.

按下1次F10,程序中申明了变量，执行了如下的程序：

```
int main() {
	Status j;
	int i = 0, l;
	QElemType d;
	SqQueue Q;
```

在“局部变量”窗口中可以看到的提示信息如下：

![](img/img2.png)

## 3.

按下1次F10，执行的程序如下：

```
	InitQueue(&Q);
```

这个函数的原型如下：

```
/* 初始化一个空队列Q */
Status InitQueue(SqQueue *Q) {
	Q->front = 0;
	Q->rear = 0;
	return  OK;
}
```

由上面的函数原型，可以明显地知道在“局部变量”窗口中内存的变化情况如下：

![](img/img3.png)

## 4.

按下1次F10，执行的程序语句如下：

```
	printf("初始化队列后，队列空否？%u(1:空 0:否)\n", QueueEmpty(Q));
```

这个函数的原型如下：

```
/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) /* 队列空的标志 */
		return TRUE;
	else
		return FALSE;
}
```

猜测在“局部变量”窗口中的返回值为TRUE，结果如下：

![](img/img4.png)

## 5.

跳过非关键步骤，按下1次F10，执行的程序语句如下：

```
	do {
		/* scanf("%d",&d); */
		d = i + 100;
		if (d == -1)
			break;
		i++;
		EnQueue(&Q, d);
	} while (i<MAXSIZE - 1);
```

上面语句的作用是执行循环，在队列中插入元素。

# 总结