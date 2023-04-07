/**
 * Base string class
 */
class Base
{
    protected string _m_string;

    public Base(string row)
    {
        this._m_string = row;
    }

    /**
     * Get string length
     */
    public int Length()
    {
        return this._m_string.Length;
    }
};

/**
 * Child numeric string class
 */
class Child: Base
{
    public Child(int number): base(number.ToString())
    {
        //
    }

    /**
     * Get string
     */
    public string Get()
    {
        return this._m_string;
    }

    /**
     * Remove character from the string
     */
    public void Remove(char character)
    {
        for (int i = 0; i < this._m_string.Length; i++)
        {
            if (this._m_string[i] == character)
            {
                this._m_string = this._m_string.Remove(i, 1);

                i--;
            }
        }
    }
};

class Application
{
    static void Main(string[] args)
    {
        Child row = new Child(1234567890);

        System.Console.WriteLine("____ Initial Child object (numeric string):");
        System.Console.WriteLine(row.Get());
        
        System.Console.WriteLine("____ Child object (numeric string) length:");
        System.Console.WriteLine(row.Length());

        row.Remove('5');

        System.Console.WriteLine("____ Child object (numeric string), after removing '5' character:");
        System.Console.WriteLine(row.Get());
        
        System.Console.WriteLine("____ Child object (numeric string) length, after removing '5' character:");
        System.Console.WriteLine(row.Length());

        row.Remove('2');

        System.Console.WriteLine("____ Child object (numeric string), after removing '2' character:");
        System.Console.WriteLine(row.Get());
        
        System.Console.WriteLine("____ Child object (numeric string) length, after removing '2' character:");
        System.Console.WriteLine(row.Length());
    }
}