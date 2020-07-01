#ifndef SYMBOL_H
#define SYMBOL_H

/****************************************************************************
symbol.h
Implements a symbol table for a simple calculator.
****************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// symbol

class symbol {
public:
	symbol();
	virtual ~symbol();

// Attributes
public:
	symbol* m_next;			// next symbol in bucket list
	char* m_name;			// symbol name
	double m_value;			// value attached to symbol

// Operations
public:
	int create(const char* name);
};

/////////////////////////////////////////////////////////////////////////////
// symboltable

#define BUCKET_SIZE 211				// prime number

class symboltable {
public:
	symboltable();
	virtual ~symboltable();
	
// Attributes
protected:
	symbol* m_bucket[BUCKET_SIZE];		// array of buckets

// Operations
protected:
	int hash(const char* name) const;
public:
	symbol* install(const char* name);
};

#endif
