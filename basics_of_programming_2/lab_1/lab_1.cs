using System.Collections.Generic;
using System.Text.RegularExpressions;

class Row
{
    private string _m_row;
    
    public Row(string row = "")
    {
        this._m_row = row;
    }

    /**
     * Get Row string
     */
    public string Get()
    {
        return this._m_row;
    }

    /**
     * Get Row length
     */
    public int Length()
    {
        return this._m_row.Length;
    }
}

class Text
{
    private List<Row> _m_rows = new List<Row>();

    public Text(Row[] rows)
    {
        this._m_rows.AddRange(rows);
    }

    /**
     * Add Row to the Text
     */
    public void Add(Row row)
    {
        this._m_rows.Add(row);
    }

    /**
     * Delete Row from The Text
     */
    public void Del(Row row)
    {
        this._m_rows.Remove(row);
    }

    /**
     * Clear Text from the Rows
     */
    public void Clear()
    {
        this._m_rows.Clear();
    }

    /**
     * Get the Text length (sum of all the Rows length)
     */
    public int Length()
    {
        int length = 0;

        foreach (Row row in this._m_rows)
        {
            length += row.Length();
        }

        return length;
    }

    /**
     * Get longest Text Row
     */
    public Row Longest()
    {
        if (this._m_rows.Count == 0)
        {
            return new Row();
        }

        int index = 0;
        int length = 0;

        for (int i = 0; i < this._m_rows.Count; i++)
        {
            if (this._m_rows[i].Length() >= length)
            {
                index = i;
                length = this._m_rows[i].Length();
            }
        }

        return this._m_rows[index];
    }

    /**
     * Get percentage of digits in Text Rows
     */
    public double Percentage()
    {
        double count = 0;
        double length = 0;
        
        Regex regex = new Regex("[0-9]");

        foreach (Row row in this._m_rows)
        {
            length += row.Length();
            
            count += regex.Matches(row.Get()).Count;
        }

        return count / (length / 100.0);
    }

    /**
     * Print out Text Rows to the console
     */
    public void Print()
    {
        foreach (Row row in this._m_rows)
        {
            System.Console.WriteLine(row.Get());
        }
    }

    ~Text()
    {
        this._m_rows.Clear();
    }
}

class Application
{
    static void Main(string[] args)
    {
        Text text = new Text(new Row[] {new Row("First row."), new Row("Second row.")});
        
        System.Console.WriteLine("____ Initial Text object:");
        
        text.Print();

        Row forDeletionPurposesRow = new Row("For deletion purposes Row.");

        text.Add(forDeletionPurposesRow);
        text.Add(new Row("Third row."));
        
        System.Console.WriteLine("____ Text object (with additional two Row objects):");
        
        text.Print();
        
        text.Del(forDeletionPurposesRow);
        
        System.Console.WriteLine("____ Text object (after deletion Row):");
        
        text.Print();

        System.Console.WriteLine("____ Text object longest Row:");
        System.Console.WriteLine(text.Longest().Get());

        text.Clear();

        System.Console.WriteLine("____ Text object after clean up:");
        
        text.Print();
        
        text.Add(new Row("1-st row."));
        text.Add(new Row("Last (2-nd) row."));

        System.Console.WriteLine("____ Text object (with additional two Row objects):");
        
        text.Print();

        System.Console.WriteLine("____ Text object length:");
        System.Console.WriteLine(text.Length());
        
        System.Console.WriteLine("____ Text object percentage of digits in Rows:");

        System.Console.WriteLine(text.Percentage());
    }
}