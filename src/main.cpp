#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

const char e = 'e';

// this is a derivative calculator written in cpp

class Term {
    public:
        int coefficient;
        int exponent;
        int sign; // 1 pos -1 neg

        Term(int sign, int coefficient, int exponent) : sign(sign), coefficient(coefficient), exponent(exponent) {}

        static Term parse(const string& str) {
            int sign = (str[0] == '-') ? -1 : 1;
            int coefficient, exponent;
            sscanf(str.c_str(), "%F*[-+]%dx^%d", &coefficient, exponent);
            return Term(sign, coefficient, exponent); 
        }

        Term derive () {
            return Term(sign, coefficient * exponent, exponent - 1);
        }

        string toString() {
            ostringstream oss;
            if (sign == -1) {
                oss << "-";
            }
            oss << coefficient << "x^" << exponent;
            if (exponent != 1) {
                oss << exponent;
            }
        return oss.str();
        }
};

class Expression {
    public: 
        vector<Term> terms;

        static Expression parse(const string& str) {
            Expression expr;
            istreamstream iss(str);
            string termStr;
            while (getline(iss, termStr, '+')) {
                istringstream iss2(termStr);
                string subTermStr;
                while (getline(iss2, subTermStr, '-')) {
                    expr.terms.push_back(Term::parse(subTermStr));
                }
            }
            return expr;
        } 
}

Expression derive () {
    Expression derived;
    for (const Term& term : terms) {
        derived.terms.push_back(term.derive());
    }
    return derived;
}
