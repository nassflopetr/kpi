#include <iostream>

/**
 * Base string class
 */
class Base
{
    protected:
        std::string _m_string;

    public:
        Base(std::string string)
        {
            this->_m_string = string;
        }

        /**
         * Get string length
         */
        unsigned int Length()
        {
            return this->_m_string.length();
        }

        ~Base()
        {
            this->_m_string.clear();
        }
};

/**
 * Child numeric string class
 */
class Child: public Base
{
    public:
        Child(unsigned int number): Base(std::to_string(number))
        {
            //
        }

        /**
         * Get string
         */
        std::string Get()
        {
            return this->_m_string;
        }

        /**
         * Remove character from the string
         */
        void Remove(char character)
        {
            for (unsigned int i = 0; i < this->_m_string.length(); i++)
            {
                if (this->_m_string[i] == character)
                {
                    this->_m_string.erase(i, 1);

                    i--;
                }
            }
        }
};

int main()
{
    Child string(1234567890);

    std::cout << "____ Initial Child object (numeric string):" << std::endl;
    std::cout << string.Get() << std::endl;

    std::cout << "____ Child object (numeric string) length:" << std::endl;
    std::cout << string.Length() << std::endl;

    string.Remove('5');

    std::cout << "____ Child object (numeric string), after removing '5' character:" << std::endl;
    std::cout << string.Get() << std::endl;

    std::cout << "____ Child object (numeric string) length, after removing '5' character:" << std::endl;
    std::cout << string.Length() << std::endl;

    string.Remove('2');

    std::cout << "____ Child object (numeric string), after removing '2' character:" << std::endl;
    std::cout << string.Get() << std::endl;

    std::cout << "____ Child object (numeric string) length, after removing '2' character:" << std::endl;
    std::cout << string.Length() << std::endl;

    exit(0);
}