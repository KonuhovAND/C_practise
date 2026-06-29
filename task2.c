struct List {
    int Value;
    struct List *Next;
} *First;

// Написать функцию, которая разворачивает список в обратном порядке.
// (То есть последний элемент становится первым, предпоследний - вторым и т.д.)
// Функция не должна запрашивать память.
void func(){
    if(First == Null || First->Next == Null) return;
    struct List *a=First,*b=Null, *end=First;
    while(end->Next != Null){
        end = end.Next;
    }
    while(a != end){
       b= a;
       a=a-Next; 
       b->Next = end->Next;
       ed->Next = b;

    }
    First = end;
}