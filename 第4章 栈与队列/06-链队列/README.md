# 运行结果 #
![](img/result.png)

# 调试信息 #
## 1. ##
按下1次F10，先探明程序中变量的内存信息，此时的值是随意分配的。在“局部变量”窗口中看到的结果如下:

![](img/img1.png)

## 2. ##
按下第2次F10，执行的程序如下：

    int main() {
    	int i;
    	QElemType d;
    	LinkQueue q;

在“局部变量”窗口中看到的提示信息如下：

![](img/img2.png)

## 3. ##
按下1次F10，执行的程序如下：

	i = InitQueue(&q);

初始化队列，这个函数的原型如下:

    /* 构造一个空队列Q */
    Status InitQueue(LinkQueue *Q) {
    	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    	if (!Q->front)
    		exit(OVERFLOW);
    	Q->front->next = NULL;
    	return OK;
    }

在“局部变量”窗口中看到的提示信息如下;

![](img/img3.png)

## 4. ##
跳过一些非关键步骤，按下F10，执行的程序如下：

	EnQueue(&q, -5);
	EnQueue(&q, 5);
	EnQueue(&q, 10);

向队列中插入，-5，5，10这三个数据，这个函数的原型如下;

    /* 插入元素e为Q的新的队尾元素 */
    Status EnQueue(LinkQueue *Q, QElemType e) {
    	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    	if (!s) /* 存储分配失败 */
    		exit(OVERFLOW);
    	s->data = e;
    	s->next = NULL;
    	Q->rear->next = s;	/* 把拥有元素e的新结点s赋值给原队尾结点的后继，见图中① */
    	Q->rear = s;		/* 把当前的s设置为队尾结点，rear指向s，见图中② */
    	return OK;
    }

在“局部变量”窗口中看到的提示信息如下：

![](img/img4.png)


# 总结 #
## 1. ##
1个小的警告，问题不大。

    d:\visual studio code\链队列\链队列\linkqueue.c(160): warning C4477: 'printf' : format string '%u' requires an argument of type 'unsigned int', but variadic argument 1 has type 'QueuePtr'

![](img/warning.png)

学会了一个新的技能，“%u”表示“unsigned”的格式。


