/****************************************************************************
symbol.cpp
Implements a symbol table for a simple calculator.
****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "symbol.h"

/////////////////////////////////////////////////////////////////////////////
// symbol construction/destruction

symbol::symbol()
{
	m_next = NULL;
	m_name = NULL;
	m_value = 0;
}

symbol::~symbol()
{
	delete[] m_name;
}

/////////////////////////////////////////////////////////////////////////////
// symbol commands

int symbol::create(const char* name)
{
	assert(name != NULL);
	int length = strlen(name);
	m_name = new char[length + 1];
	strcpy(m_name, name);
	return 1;
}

/////////////////////////////////////////////////////////////////////////////
// symboltable construction/destruction

symboltable::symboltable()
{
	for (int i = 0; i < BUCKET_SIZE; i++) {
		m_bucket[i] = NULL;
	}
}

symboltable::~symboltable()
{
	for (int i = 0; i < BUCKET_SIZE; i++) {
		symbol* p = m_bucket[i];
		while (p != NULL) {
			symbol* next = p->m_next;
			delete p;
			p = next;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// symbol commands

int symboltable::hash(const char* name) const
{
	assert(name != NULL);
	int index = 0;
	while (*name != '\0') {
		index = index << 1 ^ *name++;
	}
	index %= BUCKET_SIZE;
	if (index < 0) {
		index = -index;
	}
	return index;
}

symbol* symboltable::install(const char* name)
{
	assert(name != NULL);
	int index = hash(name);
	symbol* p;
	for (p = m_bucket[index]; p != NULL; p = p->m_next) {
		if (strcmp(p->m_name, name) == 0) {
			return p;
		}
	}
	p = new symbol();
	p->create(name);
	p->m_next = m_bucket[index];
	m_bucket[index] = p;
	return p;
}
