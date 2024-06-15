#include <iostream>


typedef struct array{
	
	array(std::initializer_list<int> l){
		pt = new int[l.size()];
		for (int i = 0; i < l.size(); i++){
			pt[i] = l.begin()[i];
		size = l.size();
		}
	}
	array(int n){
		pt = (int*)calloc(n, sizeof(int));
		size = n;
	}
	
	int& operator[](int a){
		return pt[a];
	}
	
	
	
	array operator+(array a){
		array new_arr(a.get_size() + size);
		int i = 0;
		while (i < size){
			new_arr[i] = pt[i];
			i++;
		}
		while (i < new_arr.size){
			new_arr[i] = a[i-size];
			i++;
		}
		
		return new_arr;
	}
	
	void operator+=(array a){
		int* new_arr = new int[size + a.get_size()];
		int i = 0;
		while (i < size){
			new_arr[i] = pt[i];
			i++;
		}
		while (i < size + a.get_size()){
			new_arr[i] = a[i-size];
			i++;
		}
		
		free(pt);
		pt = new_arr;
		size = size + a.get_size();
	}
	
	void append(int n){
		int* new_arr = new int[size+1];
		for (int i = 0; i < size; i++){
			new_arr[i] = pt[i];
		}
		new_arr[size] = n;
		free(pt);
		
		pt = new_arr;
		size++;
	}	
	
	
	void print(){
		for (int i = 0; i < size; i++){
			std::cout << pt[i] << ' ';
		}
		std::cout << '\n';
	}
	
	void s_free(){
		free(pt);
	}
	
	size_t get_size(){
		return size;
	}
	
	private:
		int* pt;
		size_t size;
		
	
	
} array;







int main(){
	
	
	array arr({1, 2, 3});
	//array arr2({4, 5, 6});
	//array arr3 = arr + arr2;
	arr.print();
	//arr2.print();
	//arr3.print();
	
	
	
	/*
	int i = 0;
	while (i < 10000){
		arr.append(i);
		std::cout << i << '\n';
		i++;
	};
	std::cout << '\n' << arr.size;
	std::cin.get();*/
	
	return 0;
	
}