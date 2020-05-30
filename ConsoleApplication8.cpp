// ConsoleApplication8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Agricultural {
protected:
	int id;
	string Brand;
	string Name;
	float weight;
	int price;
public:
	Agricultural(int id, string Brand, string Name, float weight, int price) {
		this->id = id;
		this->Brand = Brand;
		this->Name = Name;
		this->weight = weight;
		this->price = price;
	}
	Agricultural() {
		id = 0;
		Brand = "";
		Name = "";
		weight = 0;
		price = 0;
	};
	virtual void Set_ID(int id) {
		this->id = id;
	};
	virtual int Get_ID() {
		return this->id;
	};

	virtual void Set_Brand(string Brand) {
		this->Brand = Brand;
	};
	virtual string Get_Brand() {
		return this->Brand;
	};

	virtual void Set_Name(string Name) {
		this->Name = Name;
	};
	virtual string Get_Name() {
		return this->Name;
	};

	virtual void Set_Weight(float weight) {
		this->weight = weight;
	};
	virtual float Get_Weight() {
		return this->weight;
	};
	virtual void Set_Price(int price) {
		this->price = price;
	};
	virtual int Get_Price() {
		return this->price;
	};
	virtual void Output() {
		cout << "Машина №" << id << "\n" << "Название - " << Name
			<< "\nМарка - " << Brand << "\nВес - " << weight << "\nЦена - " << price << endl;
	};
};

class Engine {
private:
	string engine_name;
	float power;
	float engine_volume;
public:
	Engine() {
		this->engine_name="";
		this->power=0;
		this->engine_volume=0;
	};
	Engine(string _engine_name, float _power, float _engine_volume) {
		this->engine_name = _engine_name;
		this->power = _power;
		this->engine_volume = _engine_volume;
	};

	void Output() {
		cout << "Название/модель двигателя - " << engine_name << "\n" << "Мощность двигателя - " << power << "\n" <<
			"Объём двигателя - " << engine_volume << endl;
	}
};

template <class T>
class Vector {
private:
	T* arr;
	int size;
public:
	Vector();
	Vector(int size);
	~Vector();
	T& operator [](const int current);
	void ShellSort();
	void Insert(int n, T& element);
	string OutputVector(int current);
	int Length() const;
	


	friend ostream& operator << (ostream& out, const Vector& v) {
		v.arr->Output();
		out << endl << endl;
		return out;
	};
};

template<class T>
Vector<T>::Vector() {
	this->size = 0;
	arr = new T[size];
}

template<class T>
Vector<T>::Vector(int count_of_elem) {
	
	this->size = count_of_elem;
	arr = new T[count_of_elem];
}
template<class T>
Vector<T>::~Vector() {
	delete[]arr;
}

template<class T>
T& Vector<T>::operator[](int current){
	return arr[current];
}

template<class T>

void Vector<T>::Insert(int n, T& element) {
	if (n<0 || n>size) throw "Неверный индекс или вектор переполнен";
	T* temp = new T[size + 1];
	for (int i = 0; i < n; i++) {
		temp[i] = arr[i];
	}
	temp[n] = element;
	for (int i = n + 1; i < size + 1; i++) {
		temp[i] = arr[i - 1];
	}
	delete[] arr;
	arr = temp;
	size++;
}
template<class T>
int Vector<T>::Length() const {
	return size;
}

template<class T>
void Vector<T>::ShellSort() {
	int step = size / 2;
	while (step > 0) {
		for (int i = 0; i < size - step; i++) {
			int j = i;
			while (j >= 0 && arr[j].GetPrice() > arr[j + step].GetPrice()) {
				std::swap(arr[j], arr[j + step]);
				j -= step;
			}
		}
		step /= 2;
	}
}

template<class T>
string Vector<T>::OutputVector(int current) {
	string strID, strPRICE, strWEIGHT, strNAME, strBRAND;
	
	strID = to_string(arr[current].Get_ID());
	strPRICE = to_string(arr[current].Get_Price());
	strWEIGHT = to_string(arr[current].Get_Weight());
	strNAME = arr[current].Get_Name();
	strBRAND = arr[current].Get_Brand();

	return "Машина №" + strID+ ", "+ "Цена -" + strPRICE + " тыс.руб., " + "Вес - "+ strWEIGHT + " т., " + "Название - "+ strNAME +", " + "Марка - " +strBRAND + "\n";
}


class Tractor: virtual public Agricultural, public Engine {
private:
	//Класс тяги трактора в кН.
	int drawbar_category;
public:
	Tractor() : Agricultural(),Engine() {
		this->drawbar_category = 0;
	}

	Tractor(int id, string Brand, string Name, float weight, int price,string engine_name,float power,float engine_volume, int drawbar_category) : Agricultural(id, Brand, Name, weight, price), Engine(engine_name,power,engine_volume){
	
		this->drawbar_category = drawbar_category;
	}
	void Output() {
		Agricultural::Output();
		Engine::Output();
		cout << "Тяговой класс - " << drawbar_category << endl;
	}
};

int main()
{
	setlocale(LC_ALL,"Russian");

	string brand, name;
	float weight;
	int price, numbers_of_gears;
	bool overflow;
	
	Vector<Tractor> v;
	Tractor MTZ(0, "BELARUS", "MTZ-85", 3.0, 600,"D-2",123.1,250.2, 14);
	Tractor MTZ2(1, "BELARUS", "MTZ-90", 4.2, 800, "D-2", 123.1, 250.2, 9);
	Tractor MTZ3(1, "BELARUS", "MTZ-90", 4.2, 800, "D-2", 123.1, 250.2, 9);
	try {
		v.Insert(0, MTZ);
		v.Insert(1, MTZ2);
		v.Insert(-1, MTZ3);
	}
	catch (const char * exception) {
		cout << "Ошибка - " << exception << endl;
	}
	
	cout << " Количество элементов в векторе - " << v.Length() << endl;

	for (int i = 0; i < v.Length(); i++) {
		
		v[i].Output();
		cout << endl<<endl;
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
