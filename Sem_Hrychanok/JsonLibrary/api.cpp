﻿
#include "pch.h"
#include "api.h"
#include "parser.h"

KeyValuePair::KeyValuePair(std::string key, Value* value)
{
	this->key = key;
	this->value = value;
}


std::string KeyValuePair::getKey() const
{
	return key;
}

Value* KeyValuePair::getValue() const
{
	return value;
}

std::string KeyValuePair::serialize() const
{
	std::string str = "\"";
	str.append(key);
	str.append("\":");
	str.append(value->serialize());
	return str;
}

BoolValue::BoolValue(bool value) : value(value)
{
}

bool BoolValue::get() const
{
	return value;
}

std::string BoolValue::serialize() const
{
	if (value == true) return "true";
	else return "false";
}

NumberValue::NumberValue(double value) : value(value)
{
}

std::string NumberValue::serialize() const
{
	return std::to_string(value);
}

double NumberValue::get() const
{
	return value;
}

StringValue::StringValue(std::string value) : value(value)
{
}

std::string StringValue::get() const
{
	return value;
}

void StringValue::append(char c)
{
	value += c;
}

std::string StringValue::serialize() const
{
	std::string str = "\"";
	str.append(value);
	str.append("\"");
	return str;
}

ArrayValue::ArrayValue()
{
	array = DynamicArray<Value*>();
}

ArrayValue::~ArrayValue()
{
	array.~DynamicArray();
}

void ArrayValue::append(Value* element)
{
	array.append(element);
}


Value* ArrayValue::get(int index) const {
	return array.getElementAt(index);
}

std::string ArrayValue::serialize() const
{
	std::string str = "[";
	for (size_t i = 0; i < array.getSize(); i++)
	{
		str.append(array.getElementAt(i)->serialize());
		if (i+1 < array.getSize()) { str.append(","); }
	}
	str.append("]");
	return str;
}

int ArrayValue::getSize() const
{
	return array.getSize();
}

ObjectValue::ObjectValue()
{
	array = DynamicArray<KeyValuePair>();
}

ObjectValue::~ObjectValue()
{
	array.~DynamicArray();
}

void ObjectValue::append(const KeyValuePair& pair)
{
	array.append(pair);
}

const KeyValuePair& ObjectValue::get(int index) const {
	return array.getElementAt(index);
}

int ObjectValue::getSize() const {
	return array.getSize();
}

std::string ObjectValue::serialize() const
{
	std::string str = "{";
	for (size_t i = 0; i < array.getSize(); i++)
	{
		str.append(array.getElementAt(i).serialize());
		if (i + 1< array.getSize()) { str.append(","); }
	}
	str.append("}");
	return str;
}

DynamicArray<KeyValuePair> ObjectValue::getArray() const
{
	return array;
}

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
Value* JSON::deserialize(const std::string& string)
{
	parser parser;
	return parser.deserealize(string);
}

// - provede serializaci do JSON řetězce
std::string JSON::serialize(const Value* value)
{
	return value->serialize();
}

std::string NullValue::serialize() const
{
	return "null";
}