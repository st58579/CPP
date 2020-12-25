#include <string>
#include <exception>
// - šablona s parametrem datového typu uložených hodnot
// - není povoleno užití STL kontejnerů ani jiných knihoven pro ukládání dat
// - realizace musí využívat dynamicky alokované pole, spojový seznam nebo jinou vhodnou Vámi implementovanou ADS 

template<typename T>
class DynamicArray {
	struct Node {
		Node* next;
		T data;
		Node(const T& data) {
			this->data = data;
			next = nullptr;
		}
	};
public:
	DynamicArray();
	~DynamicArray();

	// - přidá element na konec pole
	void append(const T& element);

	// - výjimky při neplatném nebo nekorektním indexu
	const T& getElementAt(int index) const;

	// - vrací velikost (počet prvků) v poli
	int getSize() const;
private:
	Node* first;
	Node* actual;
	Node* last;
	int size;
};

///////////////////////////////////////////////////////////////////////////////

// - definuje pár klíč (řetězec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu
class KeyValuePair {
public:
	KeyValuePair(std::string key, Value* value);

	// - vrátí klíč
	std::string getKey() const;
	// - vrátí hodnotu
	Value* getValue() const;
private:
	std::string key;
	Value* value;
};

///////////////////////////////////////////////////////////////////////////////

// JSON hodnota - reprezentuje abstraktního předka pro základní datové typy v JSON (string, number, object, array, bool, null)
class Value
{
public:
	// serializuje hodnotu do podoby JSON reprezentace
	virtual std::string serialize() const = 0;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON null
class NullValue :
	public Value
{
public:
	std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON bool
class BoolValue :
	public Value
{
public:
	BoolValue(bool value);

	// - vrací bool hodnotu
	bool get() const;
	std::string serialize() const override;
private:
	bool value;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON číslo
class NumberValue :
	public Value
{
public:
	NumberValue(double value);

	// - vrací číselnou hodnotu 
	std::string serialize() const override;
	double get() const;
private:
	double value;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON řetězec (string)
class StringValue :
	public Value
{
public:
	StringValue(std::string value);

	// - vrací řetězcovou hodnotu
	std::string get() const;
	void append(char c);
	std::string serialize() const override;
private:
	std::string value;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON pole
class ArrayValue :
	public Value
{
public:
	ArrayValue();
	~ArrayValue();

	// - přidá element na konec pole
	void append(Value* element);
	std::string serialize() const override;
private:
	// - atribut DynamicArray<Value*> pro uchování jednotlivých elementů v poli
	DynamicArray<Value*> array;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON objekt
class ObjectValue :
	public Value
{
public:

	ObjectValue();
	~ObjectValue();

	// - přidá klíč-element do objektu
	void append(const KeyValuePair& pair);
	std::string serialize() const override;
private:
	// - atribut DynamicArray<KeyValuePair> pro uchování jednotlivých hodnot a klíčů v objektu
	DynamicArray<KeyValuePair> array;
};

///////////////////////////////////////////////////////////////////////////////

// - třída pro práci s JSON
class JSON
{
public:
	// - provede deserializaci řetězce na vytvořené objekty
	// - přečtu znak a rozhodnu se (uvedený postup předpokládá čtení bez přeskakování bílých znaků)
	// -- '{' - začínám číst objekt
	// -------- čtu znaky, pak musí být dvojtečka, potom volám rekurzivně deserialize();  následuje čárka nebo '}', podle situace se čtení opakuje
	// -- '[' - začínám číst pole
	// -------- volám rekurzivně deserialize(); následuje čárka nebo ']', podle situace se čtení opakuje
	// -- '"' - začínám číst řetězec - pozor na escapované uvozovky
	// -- [-0123456789] - začínám číst číslo - načtu všechny číslice (pozor na možnou desetinnou  tečku)
	// -- 'n' - 'null' – načtu zbylé znaky a kontroluji, že je to opravdu ‚null‘ a ne něco jiného
	// -- 't' - 'true' - dtto
	// -- 'f' - 'false' - dtto
	// -- cokoliv jiného - vyvolávám výjimku
	// - není přípustné vracet nullptr
	// - deserializace musí být rozumně implementována - není přípustné zde napsat jednu extrémně  dlouhou metodu
	static Value* deserialize(const std::string& string);

	// - provede serializaci do JSON řetězce
	static std::string serialize(const Value* value);
	static size_t position; // pointer to actual position in array
};

///////////////////////////////////////////////////////////////////////////////


template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	first = nullptr;
	actual = nullptr;
	size = 0;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	while (first != nullptr) {
		Node* tmp = first->next;
		delete first;
		first = tmp;
	}
}

template<typename T>
inline void DynamicArray<T>::append(const T& element)
{
	if (first == nullptr) {
		first = new Node(element);
	}
	else {
		actual = first;
		while (actual.next != nullptr) {
			actual = actual.next;
		}
		actual.next = new Node(element);
	}
	size++;
}

template<typename T>
inline const T& DynamicArray<T>::getElementAt(int index) const
{
	if (index > size - 1) {
		throw std::exception("wrong index");
	}
	actual = first;
	for (size_t i = 0; i < index; i++)
	{
		actual = actual.next;
	}
	return &actual.data;
}

template<typename T>
inline int DynamicArray<T>::getSize() const
{
	return size;
}