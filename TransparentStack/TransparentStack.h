
#ifndef TRANSPARENTSTACK_H
#define TRANSPARENTSTACK_H
#include <iostream>
#include <stack>
using namespace std;

template <typename T> 
class TransparentStack:

	template <class transparent_stack>
	public transparent_stack<T, vector<T>, greater<T>>::transparent_stack {
		public:
		int peek(size_t idx){
			TransparentStack newts = this;
			int num = this.size - idx -1;
			for(unsgined int =0; i< num; i++){
				newts.pop_back();
			}
			return newts.back();
		};
	
};
#endif
