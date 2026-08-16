#include <thread>
#include <vector>
#include <iostream>
int main(){std::vector<int>v(1000,1);long long sum=0;std::vector<std::thread>ts;for(int t=0;t<4;t++)ts.emplace_back([&,t]{for(size_t i=t;i<v.size();i+=4)sum+=v[i];});for(auto&t:ts)t.join();std::cout<<sum<<'\n';}