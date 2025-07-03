//3.Binary Operator Oveloading
#include<iostream> 
using namespace std;

class TestClass {
private:
	int real, over;
public:
	TestClass(int rl = 0, int ov = 0) {
		real = rl;
		over = ov;
        cout << "Testclass : " << real << endl;
	}

	TestClass operator + (TestClass const &obj) {
		TestClass result;
		result.real = real + obj.real;
		result.over = over + obj.over;
        cout << "Te : " << real << endl;
        cout << "Tes : " << obj.real << endl;
		return result;
	}
	void print() {
		cout << real << " + i" << over << endl;
	}
};
int main()
{
	TestClass c1(9, 5), c2(4, 3);
	TestClass c3 = c1 + c2;
	c3.print();
}  