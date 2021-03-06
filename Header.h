#if !defined(__SOLVER_H)
#define __SOLVER_H
#include <iostream>
#include <string>
using namespace std;
// Defines
#define MAX_EXPR_LEN   255
#define MAX_TOKEN_LEN  80

struct TCALCNode
{
	double value;

	TCALCNode *left;

	TCALCNode *right;

	TCALCNode(double _value = 0.0, TCALCNode *_left = NULL, TCALCNode *_right = NULL)
	{
		value = _value;
		left = _left;
		right = _right;
	}
};

struct TError
{
	char *error;
	int pos;

	TError() {	};

	TError(char *_error, int _pos)
	{
		error = _error;
		pos = _pos + 1;
	}
};

class TCALC
{
private:

	TCALCNode *root;
	char *expr;
	char curToken[MAX_TOKEN_LEN];

	enum {
		CALC_PLUS, CALC_MINUS, CALC_MULTIPLY, CALC_DIVIDE, CALC_PERCENT, ALC_POWER,
		CALC_SIN, CALC_COS, CALC_TG, CALC_EXP, CALC_LG, CALC_LN, CALC_SQRT, CALC_X, CALC_L_BRACKET, CALC_R_BRACKET, CALC_E, CALC_PI, CALC_NUMBER, CALC_END, CALC_G, ALC_EXP1, CALC_LEET
	} typToken; //������������ ��������, ���������

	int pos;
	const double *x;
	double result;

private:

	TCALCNode *CreateNode(double _value = 0.0, TCALCNode *_left = NULL, TCALCNode *_right = NULL);

	TCALCNode *Expr(void);

	TCALCNode *Expr1(void);

	TCALCNode *Expr2(void);

	TCALCNode *Expr3(void);

	TCALCNode *Expr4(void);

	TCALCNode *Expr5(void);


	bool GetToken(void);

	bool IsDelim(void)

	{
		return (strchr("+-*/%^()[]", expr[pos]) != NULL);    //����������� ������� 
	}

	bool IsLetter(void)

	{
		return ((expr[pos] >= 'a' && expr[pos] <= 'z') ||
			(expr[pos] >= 'A' && expr[pos] <= 'Z'));
	}

	bool IsDigit(void)

	{
		return (expr[pos] >= '0' && expr[pos] <= '9');       // ����������� �����
	}

	bool IsPoint(void)

	{
		return (expr[pos] == '.');                         //� �����
	}

	double CalcTree(TCALCNode *tree);

	void  DelTree(TCALCNode *tree);

	void SendError(int errNum);


public:

	TCALC()

	{
		result = 0.0;
		x = NULL;
		root = NULL;
	}

	~TCALC()

	{
		DelTree(root);
		root = NULL;
	}

	void SetX(const double *_x)

	{
		x = _x;
	}

	bool Compile(char *expr);

	void Decompile()

	{
		DelTree(root);
		root = NULL;
	}

	double Evaluate();

	double Evaluate(double *_x)

	{
		SetX(_x);
		return Evaluate();
	}

	double Evaluate(double x, ...)

	{
		SetX(&x);
		return Evaluate();
	}

	double GetResult(void)

	{
		return result;
	}
};
#endif
