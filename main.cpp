#include <stdio.h>

#define MaxSize 50
typedef int ElemType;
//顺序存储实现栈
typedef struct {
    ElemType data[MaxSize];//数组
    int top;//始终指向栈顶
}SqStack;

/*
 * 【代码实战步骤】依次是：初始化栈、判断栈是否为空、压栈、获取栈顶元素、弹栈。
 * */

//初始化栈
void InitStack(SqStack &S){
    S.top=-1;//初始化栈，就是S.top=-1;让栈为空，就是初始化栈
}
//判断栈是否为空
bool StackEmpty(SqStack S){
    if(-1==S.top){
        return true;
    }else{
        return false;
    }
}
//入栈(压栈)
bool Push(SqStack &S,ElemType x){
    //判断栈是否满了
    if(S.top==MaxSize-1){
        return false;
    }
    S.data[++S.top]=x;//等价于 S.top=S.top+1; S.data[S.top]=x;
    return true;
}
//获取栈顶元素
bool GetTop(SqStack S,ElemType &m){
    if(StackEmpty(S)){//判断栈是否为空
        return false;
    }
    m=S.data[S.top];//m用于存储栈顶元素
    return true;
}
//弹栈(出栈)
bool Pop(SqStack &S,ElemType &m){
    if(-1==S.top){
        return false;
    }
    m=S.data[S.top--];//出栈 等价于 m=S.data[S.top]; S.top--;
    return true;
}
int main() {
    SqStack S;//先进后出FILO LIFO
    InitStack(S);
    bool flag;
    flag=StackEmpty(S);
    if(flag){
        printf("stack is empty\n");
    }
    //入栈
    Push(S,3);//入栈元素3
    Push(S,4);//入栈元素4
    Push(S,5);//入栈元素5
    ElemType m;//用于存储获取到的栈顶元素
    flag=GetTop(S,m);//获取栈顶元素
    if(flag){
        printf("get top %d\n",m);
    }
    flag=Pop(S,m);//弹出栈顶元素
    if(flag){
        printf("pop element=%d\n",m);
    }
    return 0;
}
