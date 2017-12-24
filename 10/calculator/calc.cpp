#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "Roman_int.hpp"
using namespace std;

// the type used by the calculator
#define TYPE Roman_int
//#define TYPE double


#define NUMBER '8'
#define QUIT 'q'
#define PRINT ';'
#define NAME 'A'
#define DECLARE '#'
#define CONST '@'
#define FUNC_SQRT_T 'R'
#define FUNC_POW_T 'P'
#define ASSIGN '='

#define QUIT_W "exit"
#define DECLARE_W "let"
#define CONST_W "const"
#define FUNC_SQRT_W "sqrt"
#define FUNC_POW_W "pow"

#define RESULT "= "
#define PROMPT ">  "

// run-time checked narrowing cast (type conversion):
template<class R, class A> R narrow_cast(const A& a) {
  R r = R(a);
  if (A(r)!=a)
    throw runtime_error(string("info loss"));
  return r;
}


// holds a token
class Token {
public:
  char kind;
  TYPE value;
  string name;
  Token(char ch) :kind(ch), value(1) {}
  Token(char ch, TYPE val) :kind(ch), value(val) {}
  Token(char ch, string n) :kind(ch), name(n) {}
};


// input stream
class Token_stream {
public:
  Token_stream();
  Token get();
  void putback(Token t);
  void ignore(char c);
private:
  bool full;
  Token buffer;
};
Token_stream::Token_stream() :full(false), buffer(0) {}
void Token_stream::putback(Token t) {
  if (full)
    throw runtime_error("putback() into a full buffer");
  buffer = t;
  full = true;
}

// read characters from cin and compose a Token
Token Token_stream::get() {
  // check if we already have a token ready
  if (full) {    full = false;    return buffer;  }
  char ch = ' ';
  while (isspace(ch)) {
    ch = cin.get();
    if (ch == '\n')    return Token(PRINT);
  }

  switch (ch) {

    // single char tokens
  case QUIT:
  case PRINT:
  case DECLARE:
  case CONST:
  case ASSIGN:
  case '(':
  case ')':
  case '{':
  case '}':
  case '!':
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case ',':
    return Token(ch);

    // number tokens
    //case '.':
    //case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
  case 'i': case 'I':
  case 'v': case 'V':
  case 'x': case 'X':
  case 'l': case 'L':
  case 'c': case 'C':
  case 'd': case 'D':
  case 'm': case 'M':
 {
    cin.putback(ch);
    TYPE val;
    cin >> val;
    return Token(NUMBER, val);
  }

    // string tokens: only alphanumerics and '_', starting with alpha
  default:
    if (isalpha(ch)) {
      string s;
      s += ch;
      while (cin.get(ch) && (isalnum(ch)  ||  ch == '_'))
	s += ch;
      cin.putback(ch);

      // keyword tokens
      if (s == QUIT_W)
      	return Token(QUIT);
      if (s == DECLARE_W)
      	return Token(DECLARE);
      if (s == CONST_W)
      	return Token(CONST);
      if (s == FUNC_SQRT_W)
	return Token(FUNC_SQRT_T);
      if (s == FUNC_POW_W)
	return Token(FUNC_POW_T);

      // variable name tokens
      return Token(NAME, s);
    }
    throw runtime_error("Bad token");
  }
}
void Token_stream::ignore(char c) {
  if (full && c == buffer.kind) {
    full = false;
    return;
  }
  full = false;
  char ch = 0;
  while (cin >> ch)
    if (c == ch) return;
}


// holds one record in the symbol table
class Variable {
public:
  string name;
  TYPE value;
  bool constant;
  Variable(string n, TYPE v) :name(n), value(v), constant(false) {}
  Variable(string n, TYPE v, bool c) :name(n), value(v), constant(c) {}
};


// hold and manage a symbole table
class Symbol_table {
public:
  Symbol_table() {}
  TYPE get(string var);
  void set(string var, TYPE val);
  bool is_declared(string var);
  TYPE declare(string var, TYPE val);
  TYPE declare(string var, TYPE val, bool constant);
private:
  vector<Variable> var_table;
};
// return the value of the variable named s
TYPE Symbol_table::get(string s) {
  for (unsigned int i = 0; i < var_table.size(); ++i)
    if (var_table[i].name == s)
      return var_table[i].value;
  throw runtime_error("get: undefined variable " + s);
}
// set the value of the variable named s to v
void Symbol_table::set(string s, TYPE v) {
  for (unsigned int i = 0; i < var_table.size(); ++i)
    if (var_table[i].name == s) {
      if (var_table[i].constant)    throw runtime_error("assignment of read-only variable " + s);
      var_table[i].value = v;
      return;
    }
  throw runtime_error("set: undefined variable" + s);
}
// is var already in var_table?
bool Symbol_table::is_declared(string var) {
  for (unsigned int i = 0; i < var_table.size(); ++i)
    if (var_table[i].name == var)
      return true;
  return false;
}
// add (var, val) to var_table
TYPE Symbol_table::declare(string var, TYPE val, bool constant) {
  if (is_declared(var))
    throw runtime_error(var + " declared twice");
  var_table.push_back(Variable(var, val, constant));
  return val;
}
TYPE Symbol_table::declare(string var, TYPE val) {
  return declare(var, val, false);
}




Token_stream ts;		// our input stream
Symbol_table sym_table;		// our symbol table



TYPE expression();

// +- number !
// ({ expression })
// sqrt ( expression )
// pow ( expression, expression )
TYPE primary() {
  TYPE d;
  Token t = ts.get();
  switch (t.kind) {
  // case '-':
  //   d = primary() * (-1);
  //   break;
  // case '+':
  //   d = primary();
  //   break;
  case '(':
    d = expression();
    t = ts.get();
    if (t.kind != ')')
      throw runtime_error("')' expected");
    break;
  case '{':
    d = expression();
    t = ts.get();
    if (t.kind != '}')
      throw runtime_error("'}' expected");
    break;
  case NUMBER:
    d = t.value;
    break;

  // case FUNC_SQRT_T:
  //   t = ts.get();    if (t.kind != '(')    throw runtime_error("'(' expected");
  //   d = expression();
  //   if (d < 0)
  //     throw runtime_error("square root of negtive");
  //   t = ts.get();    if (t.kind != ')')    throw runtime_error("')' expected");
  //   d = sqrt(d);
  //   break;

  // case FUNC_POW_T: {
  //   t = ts.get();    if (t.kind != '(')    throw runtime_error("'(' expected");
  //   d = expression();
  //   t = ts.get();    if (t.kind != ',')    throw runtime_error("',' expected");
  //   int p = narrow_cast<int>(expression());
  //   t = ts.get();    if (t.kind != ')')    throw runtime_error("')' expected");
  //   d = pow(d, p); 
  //   break;
  //}

  case DECLARE:
  case CONST:
  {
    char dec = t.kind;
    t = ts.get();    if (t.kind != NAME)    throw runtime_error("name expected in declaration");
    string var = t.name;
    t = ts.get();    if (t.kind != ASSIGN)    throw runtime_error("= missing in declaration of " + var);
    TYPE val = expression();
    if (dec == CONST)
      sym_table.declare(var, val, true);
    else
      sym_table.declare(var, val);
    d = val;
    break;
  }

  case NAME: {
    d = sym_table.get(t.name);
    string var = t.name;
    t = ts.get();		// check if Assignment
    if (t.kind != ASSIGN)    ts.putback(t);
    else {    d = expression();    sym_table.set(var, d);    }
    break;
  }

  default:
    throw runtime_error("primary expected");
  }

  return d;
}

// primary ! ! ...
TYPE factorial() {
  TYPE left = primary();

  while (true) {
    Token t = ts.get();
    if (t.kind == '!') {	// calculate factorial
      TYPE f(1);
      for (int i = 1; i <= left.as_int(); ++i)
	f *= i;
      left = f;
    }
    else {
      ts.putback(t);
      return left;
    }
  }
}

// factorial */% factorial ...
TYPE term() {
  TYPE left = factorial();
  Token t = ts.get();

  while (true) {
    switch(t.kind) {
    case '*':
      left *= factorial().as_int();
      t = ts.get();
      break;
    case '/': {
      TYPE d = factorial();
      if (d.as_int() == 0)
	throw runtime_error("divide by zero");
      left /= d.as_int();
      t = ts.get();
      break;
    }
    case '%': {
      int i1 = left.as_int();
      int i2 = factorial().as_int();
      if (i2 == 0)
	throw runtime_error("%: divide by zero");
      left = i1 % i2;
      t = ts.get();
      break;
    }
    default:
      ts.putback(t);
      return left;
    }
  }
}

// term +- term ...
TYPE expression() {
  TYPE left = term();
  Token t = ts.get();

  while (true) {
    switch (t.kind) {
    case '+':
      left += term().as_int();
      t = ts.get();
      break;
    case '-':
      left -= term().as_int();
      t = ts.get();
      break;
    default:
      ts.putback(t);
      return left;
    }
  }
}


// expression evaluation loop:
// QUIT
// PRINT
// expression
void calculate() {
  while (cin) try {
      cout << PROMPT;
      Token t = ts.get();
      while (t.kind == PRINT)	t = ts.get();
      if (t.kind == QUIT) {	cout << "Goodbye!\n";	return;      }
      ts.putback(t);
      cout << RESULT << expression() << endl;
    }
    catch (exception& e) {
      cerr << e.what() << endl;
      ts.ignore(PRINT);		// clean_up_mess();
    }
}


// create some useful definitions  &  calculate
int main() {

  try {

    // predefine names:
    //sym_table.declare("pi", 3.1415926535, true);
    //sym_table.declare("e", 2.7182818284, true);

    calculate();
    return 0;
  }

  catch(exception& e) {
    cerr << e.what() << endl;
    return 1;
  }

  catch(...) {
    cerr << "exception\n";
    return 2;
  }

  return 0;
}
