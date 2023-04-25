#include <iostream>
#include <time.h>
#include <math.h>

/**
 * Division by zero custom exception
 */
class DivideByZeroException : public std::exception {
    private:
        std::string message;

    public:
        DivideByZeroException(std::string message) : message(message)
        {
            //
        }

        std::string what()
        {
            return message;
        }
};

class Expression
{
    private:
        int _m_a;
        int _m_b;
        int _m_c;

    public:
        Expression(int a = 0, int b = 0, int c = 0)
        {
            this->_m_a = a;
            this->_m_b = b;
            this->_m_c = c;
        }

        /**
         * Get expression result
         */
        float Get()
        {
            if (this->_m_c == 0)
            {
                throw DivideByZeroException(
                    "(8 * log(b - 1) - c) / (a * 2 + b / c) expression. Division by zero (c = 0). (a = "
                    + std::to_string(this->_m_a) + "; b = " + std::to_string(this->_m_b) + "; c = "
                    + std::to_string(this->_m_c) + ")."
                );
            }

            float divider = (this->_m_a * 2 + this->_m_b / this->_m_c);

            if (divider == 0)
            {
                throw DivideByZeroException(
                    "(8 * log(b - 1) - c) / (a * 2 + b / c) expression. Division by zero. ((a * 2 + b / c) = 0). (a = "
                    + std::to_string(this->_m_a) + "; b = " + std::to_string(this->_m_b) + "; c = " + std::to_string(this->_m_c) + ")."
                );
            }

            return (float) (8 * log(this->_m_b - 1) - this->_m_c) / divider;
        }

        /**
         * Get object a property value
         */
        int GetA()
        {
            return this->_m_a;
        }

        /**
         * Get object b property value
         */
        int GetB()
        {
            return this->_m_b;
        }

        /**
         * Get object c property value
         */
        int GetC()
        {
            return this->_m_c;
        }

        /**
         * Set value for object a property
         */
        void SetA(int a)
        {
            this->_m_a = a;
        }

        /**
         * Set value for object b property
         */
        void SetB(int b)
        {
            this->_m_b = b;
        }

        /**
         * Set value for object c property
         */
        void SetC(int c)
        {
            this->_m_c = c;
        }
};

int main()
{
    const unsigned int LENGTH = 15;

    std::srand((unsigned) time(NULL));

    Expression expressions[LENGTH];

    for (int i = 0; i < LENGTH; i++)
    {
        int a = (int) rand();
        int b = (int) rand();
        int c = (int) rand();

        if (i == 0) {
            // Check first exception
            c = 0;
        } else if (i == 1) {
            // Check second exception
            a = 0;
            b = 0;
        }

        expressions[i] = Expression(a, b, c);

        try {
            float result = expressions[i].Get();

            std::cout << "(8 * log(b - 1) - c) / (a * 2 + b / c) = " << result << ". (a = " << a << "; b = " << b
                      << "; c = " << c << ")." << std::endl;
        } catch (DivideByZeroException e) {
            std::cout << e.what() << std::endl;
        } catch (...) {
            std::cout << "Something goes wrong." << std::endl;
        }
    }

    exit(0);
}