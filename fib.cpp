#include<iostream>
#include<map>
using namespace std;

template<typename T>
constexpr auto T1(const pair<T,T> & a) -> decltype(pair<T,T>{}){
  return make_pair(a.second,a.first+a.second);
}
template<typename T>
constexpr auto T2(const pair<T,T> & b) -> decltype(pair<T,T>{}){
  return make_pair(2*b.first*b.second-b.first*b.first,b.first*b.first+b.second*b.second);
}
template<size_t N,typename T = unsigned long long>
constexpr auto fib_(){
  return (N%2)?T1<T>(fib_<N-1,T>()) : T2<T>(fib_<N/2,T>());
}
template<>
constexpr auto fib_<1>(){ return make_pair(1,1);}

template<size_t N>
constexpr auto fib(){
  return fib_<N>().first;
}

int main(){
  unsigned long long x = fib<90>();
  std::cout<<x<<std::endl;
  return 0;
}
