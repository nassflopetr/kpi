#include <iostream>
#include <vector>
#include <regex>

class Row
{
    private:
        std::string _m_row;

    public:
        Row(std::string row = "")
        {
            this->_m_row = row;
        }

        /**
         * Get Row string
         */
        std::string Get()
        {
            return this->_m_row;
        }

        /**
         * Get Row length
         */
        unsigned int Length()
        {
            return this->_m_row.length();
        }

        ~Row()
        {
            this->_m_row.clear();
        }
};

class Text
{
    private:
        std::vector<Row> _m_rows;

    public:
        Text(Row rows[], unsigned int size)
        {
            for (unsigned int i = 0; i < size; i++)
            {
                this->_m_rows.push_back(rows[i]);
            }
        }

        /**
         * Add Row to the Text
         */
        void Add(Row row)
        {
            this->_m_rows.push_back(row);
        }

        /**
         * Delete Row from The Text
         */
        void Del(Row row)
        {
            for (unsigned int i = this->_m_rows.size() - 1; i >= 0; i--)
            {
                if (this->_m_rows[i].Get() == row.Get())
                {
                    this->_m_rows.erase(this->_m_rows.begin() + i);

                    break;
                }
            }
        }

        /**
         * Clear Text from the Rows
         */
        void Clear()
        {
            this->_m_rows.clear();
        }

        /**
         * Get the Text length (sum of all the Rows length)
         */
        unsigned int Length()
        {
            unsigned int length = 0;

            for (Row row : this->_m_rows)
            {
                length += row.Length();
            }

            return length;
        }

        /**
         * Get longest Text Row
         */
        Row Longest()
        {
            if (this->_m_rows.size() == 0)
            {
                return Row();
            }

            unsigned int index = 0;
            unsigned int length = 0;

            for (unsigned int i = 0; i < this->_m_rows.size(); i++)
            {
                if (this->_m_rows[i].Length() >= length)
                {
                    index = i;
                    length = this->_m_rows[i].Length();
                }
            }

            return this->_m_rows[index];
        }

        /**
         * Get percentage of digits in Text Rows
         */
        double Percentage()
        {
            double count = 0.0;
            double length = 0.0;

            std::regex regex("[0-9]");

            for (Row row : this->_m_rows)
            {
                length += row.Length();

                std::string row_string = row.Get();

                auto digits_begin = std::sregex_iterator(row_string.begin(), row_string.end(), regex);
                auto digits_end = std::sregex_iterator();

                count += std::distance(digits_begin, digits_end);
            }

            return count / (length / 100.0);
        }

        /**
         * Print out Text Rows to the console
         */
        void Print()
        {
            for (Row row : this->_m_rows)
            {
                std::cout << row.Get() << std::endl;
            }
        }

        ~Text()
        {
            this->_m_rows.clear();
        }
};

int main()
{
    Row rows[] = {Row("First row."), Row("Second row.")};

    Text text(rows, 2);

    std::cout << "____ Initial Text object:" << std::endl;

    text.Print();

    Row forDeletionPurposesRow("For deletion purposes Row.");

    text.Add(forDeletionPurposesRow);
    text.Add(Row("Third row."));

    std::cout << "____ Text object (with additional two Row objects):" << std::endl;

    text.Print();

    text.Del(forDeletionPurposesRow);

    std::cout << "____ Text object (after deletion Row):" << std::endl;

    text.Print();

    std::cout << "____ Text object longest Row:" << std::endl;
    std::cout << text.Longest().Get() << std::endl;

    text.Clear();

    std::cout << "____ Text object after clean up:" << std::endl;

    text.Print();

    text.Add(Row("1-st row."));
    text.Add(Row("Last (2-nd) row."));

    std::cout << "____ Text object (with additional two Row objects):" << std::endl;

    text.Print();

    std::cout << "____ Text object length:" << std::endl;
    std::cout << text.Length() << std::endl;

    std::cout << "____ Text object percentage of digits in Rows:" << std::endl;
    std::cout << text.Percentage() << std::endl;

    exit(0);
}