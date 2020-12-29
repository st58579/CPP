#ifndef __API_H
#define __API_H

#include <string>
#include <exception>
#include "DynamicArray.h"
#include "platform.h"

// JSON hodnota - reprezentuje abstraktního předka pro základní datové typy v JSON (string, number, object, array, bool, null)
class DLL_SPEC Value
{
public:
	// serializuje hodnotu do podoby JSON reprezentace
	virtual std::string serialize() const = 0;
};

///////////////////////////////////////////////////////////////////////////////

// - definuje pár klíč (řetězec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu
class DLL_SPEC KeyValuePair :
	public Value
{
public:
	KeyValuePair(std::string key, Value* value);

	// - vrátí klíč
	std::string getKey() const;
	// - vrátí hodnotu
	Value* getValue() const;
	std::string serialize() const override;
private:
	std::string key;
	Value* value;
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
class DLL_SPEC BoolValue :
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
class DLL_SPEC NumberValue :
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
class DLL_SPEC StringValue :
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
class DLL_SPEC ArrayValue :
	public Value
{
public:
	ArrayValue();
	~ArrayValue();

	// - přidá element na konec pole
	void append(Value* element);
	Value* get(int index) const; //added by myself
	std::string serialize() const override;
	int getSize() const;
private:
	// - atribut DynamicArray<Value*> pro uchování jednotlivých elementů v poli
	DynamicArray<Value*> array;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON objekt
class DLL_SPEC ObjectValue :
	public Value
{
public:

	ObjectValue();
	~ObjectValue();

	// - přidá klíč-element do objektu
	void append(const KeyValuePair& pair);
	KeyValuePair get(int index) const; //added by myself
	int getSize() const;
	std::string serialize() const override;
	DynamicArray<KeyValuePair> getArray() const;
private:
	// - atribut DynamicArray<KeyValuePair> pro uchování jednotlivých hodnot a klíčů v objektu
	DynamicArray<KeyValuePair> array;
};

///////////////////////////////////////////////////////////////////////////////

// - třída pro práci s JSON
class DLL_SPEC JSON
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
};

///////////////////////////////////////////////////////////////////////////////


#endif