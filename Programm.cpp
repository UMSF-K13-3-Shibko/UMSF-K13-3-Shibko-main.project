#include "iostream"
using namespace std;

template <typename SomeType> class MyVector
{
private: SomeType* arr;
		 int length;

public:
	MyVector()
	{
		arr = new SomeType;
		length = 0;
	}
	MyVector(int n, const SomeType& val = SomeType())
	{
		arr = new SomeType[n];
		length = n;
		for(int i=0; i<length; i++)
			arr[i] = val;
	}
	MyVector(const MyVector<SomeType>& copy)
	{
		length = copy.length;
		arr = new SomeType[length];
		for(int i=0; i < length; i++)
			arr[i] = copy.arr[i];
	}
	~MyVector() { clear(); }

	void Insert(SomeType value, int index) { arr[index] = value; }

	int size() { return length; }
	bool empty() 
	{ 
		if(length == 0) return true;
		return false;
	}
	void clear()
	{
		delete[] arr;
		length = 0;
	}
	void resize(int newSize, SomeType value = SomeType())
	{
		SomeType* arr2 = new SomeType[newSize];
		for(int i=0; i<newSize; i++)
		{
			if(i>=size()) arr2[i] = value; 
			else arr2[i]=arr[i];
		}
		delete[] arr;

		arr = new SomeType[newSize];
		length = newSize;
		for(int i=0; i<newSize; i++)
			arr[i] = arr2[i];
		delete[] arr2;
	}
	void push_back(SomeType value = SomeType()) { resize(length+1, value); }
	void pop_back() { if(!empty()) resize(length - 1); }
	SomeType at(int index)
	{
		if(0 > index || index >= length) throw out_of_range;
		return arr[index];
	}
	SomeType front() { return arr[0]; }
	SomeType back() { return arr[length - 1]; }

	friend ostream& operator<<<SomeType>(ostream& out,const MyVector<SomeType>& dt)
	{
		for(int i=0; i<dt.length; i++)
			out << dt.arr[i] << ' ';
		return out;
	}
	friend istream& operator>><SomeType>(istream& is, MyVector<SomeType>& dt)
	{
		SomeType value;
		is >> value;
		dt.push_back(value);
		return is;
	}
	MyVector<SomeType>& operator=(const MyVector<SomeType>& right)
    {
        delete[] arr;
 
		length = right.length;
 
		arr = new SomeType[length];
        for (int i = 0; i < length; i++)
			arr[i] = right.arr[i];
        
        return *this;
    }
	friend bool operator == (const MyVector<SomeType>& left,const MyVector<SomeType>& right)
	{
		if (left.length != right.length) return false;
		for(int i=0; i < left.length; i++)
			if(left.arr[i] != right.arr[i]) return false;
		return true;
	}
	SomeType& operator[] (int i) { return arr[i]; }
	friend const MyVector<SomeType> operator+<SomeType>(const MyVector<SomeType>& left, const MyVector<SomeType>& right)
	{
		MyVector<SomeType> result(left);

		for(int i=0; i < right.length; i++)
			result.push_back(right.arr[i]);

		return result;
	}
};

int main()
{
	setlocale(LC_ALL,"RUS");
	cout << "Символьный вектор" << endl;
	MyVector<char> CharVector1(3,'l');
	MyVector<char> CharVector2(5,'o');
	cout << CharVector1 << endl;
	cout << CharVector2 << endl;
	MyVector<char> CharVector3(CharVector1);
	cout << CharVector3 << endl;
	CharVector3 = CharVector1 + CharVector2;
	cout << CharVector3 << endl;
	CharVector3.resize(4);
	cout << CharVector3 << endl;
	CharVector3.push_back('c');
	CharVector3.push_back('k');
	cout << CharVector3 << endl;
	CharVector3.pop_back();
	cout << CharVector3 << endl;
	cout << (CharVector1 == CharVector2) << endl;
	cout << CharVector1[2] << endl;
	cout << CharVector2.empty() << endl;
	CharVector2.clear();
	cout << CharVector2.empty() << endl;
	system("pause");
	return 0;
}
