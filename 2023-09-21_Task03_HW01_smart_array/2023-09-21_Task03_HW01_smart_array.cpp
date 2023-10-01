#include <iostream>
#include <Windows.h>
#include <string>

constexpr auto ARR_RESERVE = 10;

class smart_array
{
private:
	int* array;
	int f_size;
	int l_size;
	int index;
public:
	void add_element(int x) {
		if (this->index < this->l_size)
		{
			array[this->index] = x;
			this->index++;
		}
		else
		{
			this->l_size++;
		}
		if (this->l_size >= this->f_size)
		{
			this->f_size += ARR_RESERVE;
			int* array_new = new int[this->f_size] {0};
			for (auto i = 0; i < this->l_size; i++)
			{
				array_new[i] = array[i];
			}
			array[this->index] = x;
			this->l_size++;
			delete[] array;
			this->array = array_new;
		}
	}
	int get_element(int n) {
		return array[n];
	}
	smart_array(int x) {
		this->index = 0;
		this->l_size = x;
		this->f_size = this->l_size + ARR_RESERVE;
		array = new int[this->f_size] {0};
	}
	~smart_array() {
		delete[] array;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	system("pause");
}

