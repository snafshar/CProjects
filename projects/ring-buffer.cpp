#include <array>
#include <iostream>
template<class T,size_t N>class Ring{std::array<T,N>data{};size_t head=0,tail=0,count=0;public:bool push(T v){if(count==N)return false;data[tail]=v;tail=(tail+1)%N;count++;return true;}bool pop(T&v){if(!count)return false;v=data[head];head=(head+1)%N;count--;return true;}};
int main(){Ring<int,4>q;q.push(7);int x;q.pop(x);std::cout<<x<<'\n';}