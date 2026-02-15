#include<bits/stdc++.h>
using namespace std;
template<typename t1>
class myDeque
{
private:
int front_idx;
int back_idx;
size_t capacity;
size_t size;
t1*arr;
public:
myDeque(){
    front_idx=0;
    back_idx=0;
    capacity=5;
    size=0;
    arr=new t1[capacity];
}

void push_back(t1 x)
{
    if(size==capacity)
    {
        resize();
    }
    arr[back_idx]=x;
    back_idx++;
    size++;

}
void push_front(t1 x)
{
    if(size==capacity)
    {
        resize();
    }
    front_idx=(front_idx+capacity-1)%capacity;
    arr[front_idx]=x;
    size++;
}
void pop_front()
{
    front_idx=(front_idx+1+capacity)%capacity;
    size--;
}
void pop_back()
{
    back_idx--;
    size--;
}
size_t get_size()
{
    return size;
}

t1 operator[](int x)
{
   return arr[(front_idx+x)%capacity];
}
void resize()
{
    t1 * temp =new t1[2*capacity];
    for(int i=0;i<=back_idx;i++)
    {
        temp[i]=arr[i];
    }
    for(int j=front_idx;j<capacity;j++)
    {
        temp[j+capacity]=arr[i];
    }
        capacity=2*capacity;

    delete arr[];
    arr=temp;

}

};
int main()
{
    myDeque<int>dq;
    for(int i=0;i<10;i++)
    dq.push_back(i);
      for(int i=10;i<20;i++)
    dq.push_front(i);
    for(int j=0;j<20;j++)
    cout<<dq[j]<<" ";
    cout<<endl;
    for(int i=0;i<10;i+=2)
    dq.pop_back();
     for(int i=0;i<10;i+=2)
    dq.pop_front();
    for(int i=0;i<dq.get_size();i++)
    {
        cout<<dq[i]<<" ";

    }
    cout<<endl;

}


