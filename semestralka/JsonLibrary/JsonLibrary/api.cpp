#include "pch.h"
#include "api.h"



KeyValuePair::KeyValuePair(std::string key, Value* value) : key(key), value(value)
{
}

std::string KeyValuePair::getKey() const
{
	return key;
}

Value* KeyValuePair::getValue() const
{
	return value;
}

BoolValue::BoolValue(bool value) : value(value)
{
}

bool BoolValue::get() const
{
	return value;
}

NumberValue::NumberValue(double value) : value(value)
{
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

std::string ObjectValue::serialize() const
{
	return std::string();
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
	JSON::position = 0;
	_deserealize(string);
}

Value* _deserealize(const std::string& string) {
	std::string nfirstchar = "-0123456789.";
	skipWhiteSpace(string);
	if (JSON::position == string.length()) return new NullValue();
	char c = string[JSON::position];
	if (c == '{') return parseObject(string);
	else if (c == '[') return parseArray(string);
	else if (c == '\"') return parseString(string, '\"');
	else if (c == '\'') return parseString(string, '\'');
	else if (nfirstchar.find(c) != std::string::npos) return parseNumber(string);
	else if (c == 't') return parseLiteral(string, "true");
	else if (c == 'f') return parseLiteral(string, "false");
	else if (c == 'n') return parseLiteral(string, "null");
	throw std::exception("invalid json");
}

Value* parseObject(const std::string& string){
	JSON::position++;
	ObjectValue* ov = new ObjectValue();
	char c;
	while (true) {
		Value* key = _deserealize(string);
		skipWhiteSpace(string);
		c = string[JSON::position];
		if (c != ':') throw std::exception("Expecting :");
		JSON::position++;
		skipWhiteSpace(string);
		Value* value = _deserealize(string);
		skipWhiteSpace(string);
		ov->append(KeyValuePair(dynamic_cast<StringValue*>(key)->get(), value));
		c = string[JSON::position];
		if (c == ',') {
			JSON::position++;
			skipWhiteSpace(string);
		}
		else break;
	}
	if (c != '}') {
		// Response.Write(str.substring(JSON::position));
		throw std::exception("Expecting }");
	}
	JSON::position++;
	return ov;
}

Value* parseArray(const std::string& string) {
	JSON::position++;
	skipWhiteSpace(string);
	if (string[JSON::position] == ']') {
		JSON::position++;
		return new ArrayValue();
	}
	ArrayValue* a = new ArrayValue();
	char c;
	while (true) {
		Value* value = _deserealize(string);
		a->append(value);
		skipWhiteSpace(string);
		c = string[JSON::position];
		if (c == ',') {
			JSON::position++;
			skipWhiteSpace(string);
		}
		else break;
	}
	if (c != ']') {
		throw "Expecting ]";
	}
	JSON::position++;
	return a;
}

Value* parseString(const std::string& string, char quote) {
	int startIndex = ++JSON::position;
	char c;
	std::string str = "";
	while ((c = string[JSON::position]) != quote) {
		if (c == '\\') {
			JSON::position++;
			c = string[JSON::position];
			if (c == 'r') str += '\r';
			else if (c == 'n') str += '\n';
			else if (c == 't') str += '\t';
			else if (c == 'f') str += '\f';
			// Note escaped unicode not handled
			else str+=c;
		}
		else str+=c;
		JSON::position++;
	}
	JSON::position++;
	return new StringValue(str);
}

Value* parseNumber(const std::string& string) {
	int startIndex = JSON::position;
	int len = 0;
	char c;
	std::string nfirstchar = "-0123456789.";
	while (nfirstchar.find(string[JSON::position]) != std::string::npos) {
		JSON::position++;
		len++;
	}
	std::string substring = string.substr(startIndex, len);
	return new NumberValue(std::stod(substring));
}

Value* parseLiteral(const std::string& string, std::string literal) {
	if (literal.length() > string.length() - JSON::position) {
		throw "Expecting " + literal;
	}
	for (size_t i = 0; i < literal.length(); i++) {
		if (literal[i] != string[i++]) {
			throw "Expecting " + literal;
		}
	}
	if (literal == "true") { 
		return new BoolValue(true);
	}
	else if(literal == "false"){
		return new BoolValue(false);
	}
	else {
		return new NullValue();
	}
}

void skipWhiteSpace(const std::string& string) {
	while (JSON::position < string.length() && isWhiteSpace(string[JSON::position])) JSON::position++;
}

bool isWhiteSpace(char c) {
	return c == ' ' || c == '\r' || c == '\n' || c == '\t';
}

// - provede serializaci do JSON řetězce
std::string JSON::serialize(const Value* value)
{
	return value->serialize();
}
