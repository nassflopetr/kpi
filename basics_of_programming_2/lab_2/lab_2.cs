using System.Collections.Generic;
using System.Linq;

class Student
{
    private string _m_surname;
    private string _m_name;
    private string _m_patronymic;

    public Student(string surname = "", string name = "", string patronymic = "")
    {
        this._m_surname = surname;
        this._m_name = name;
        this._m_patronymic = patronymic;
    }

    /**
     * Return student surname (Property, read only logic)
     */
    public string Surname
    {
        get
        {
            return this._m_surname;
        }
    }
    
    /**
     * Return student name (Property, read only logic)
     */
    public string Name
    {
        get
        {
            return this._m_name;
        }
    }
    
    /**
     * Return student patronymic (Property, read only logic)
     */
    public string Patronymic
    {
        get
        {
            return this._m_patronymic;
        }
    }

    /**
     * Return student full name (Property, read only logic)
     */
    public string FullName
    {
        get
        {
            return this._m_surname + " " + this._m_name + " " + this._m_patronymic;
        }
    }
}

class Column
{
    private int _m_length;
    private string[] _m_column;

    public Column(int length)
    {
        this._m_length = length;
        this._m_column = new string[length];
    }

    /**
     * Add student into table (Indexer, read and write logic)
     */
    public string this[int index]
    {
        get
        {
            return this._m_column[index];
        }
        set
        {
            this._m_column[index] = value;
        }
    }

    /**
     * Get object items length (Property, read only logic)
     */
    public int Length
    {
        get
        {
            return this._m_length;
        }
    }
}

class StudentsTable
{
    public const string SurnameColumn = "Surname";
    public const string NameColumn = "Name";
    public const string PatronymicColumn = "Patronymic";

    private List<Student> _m_students_table;
    private int _m_nechay_counter;

    public StudentsTable ()
    {
        this._m_students_table = new List<Student>();
        this._m_nechay_counter = 0;
    }

    /**
     * Get table Column object (Indexer, read only logic)
     */
    public Column this[string columnName]
    {
        get
        {
            if (columnName == SurnameColumn || columnName == NameColumn || columnName == PatronymicColumn)
            {
                Column column = new Column(this._m_students_table.Count);

                for (int i = 0; i < this._m_students_table.Count; i++)
                {
                    column[i] = (string) this._m_students_table[i].GetType().GetProperty(columnName).GetValue(this._m_students_table[i]);
                }

                return column;
            }

            throw new System.ArgumentException("Invalid column name.", nameof(columnName));
        }
    }
    
    /**
     * Set Student object into the table (Indexer, write only logic) 
     */
    public Student this[int index]
    {
        set
        {
            if (value.Surname == "Нечай")
            {
                this._m_nechay_counter++;
            }

            if (this._m_students_table.ElementAtOrDefault(index) != null)
            {
                this._m_students_table[index] = value;   
            }
            else
            {
                this._m_students_table.Insert(index, value);
            }
        }
    }

    /**
     * Return count of students by surname Нечай (Property, read only logic)
     */
    public int NechayLength
    {
        get
        {
            return this._m_nechay_counter;
        }
    }
    
    /**
     * Get object items length (Property, read only logic)
     */
    public int Length
    {
        get
        {
            return this._m_students_table.Count;
        }
    }
    
    /**
     * Print out students to the console
     */
    public void Print()
    {
        for (int i = 0; i < this._m_students_table.Count; i++)
        {
            System.Console.WriteLine(this._m_students_table[i].FullName);
        }
    }

    ~StudentsTable()
    {
        this._m_students_table.Clear();
    }
}

class Application
{
    static void Main(string[] args)
    {
        StudentsTable studentsTable = new StudentsTable();
        
        System.Console.WriteLine("____ Initial StudentsTable object:");
        
        studentsTable.Print();

        System.Console.WriteLine("____ StudentsTable object (with three Student objects):");
        
        studentsTable[0] = new Student("Кирпичов", "Віктор", "Львович");
        studentsTable[1] = new Student("Патон", "Євген", "Оскарович");
        studentsTable[2] = new Student("Сікорський", "Ігор", "Іванович");

        studentsTable.Print();
        
        System.Console.WriteLine("____ StudentsTable object (with additional two Student objects):");
        
        studentsTable[3] = new Student("Нечай", "Михайло", "Потапович");
        studentsTable[4] = new Student("Плотніков", "Володимир", "Олександрович");
        
        studentsTable.Print();
        
        System.Console.WriteLine("____ Count of students by surname \"Нечай\":");
        System.Console.WriteLine(studentsTable.NechayLength);
        
        System.Console.WriteLine("____ StudentsTable object (with additional one Student object):");
        
        studentsTable[5] = new Student("Нечай", "Ярослав", "Іванович");

        studentsTable.Print();
        
        System.Console.WriteLine("____ Count of students by surname \"Нечай\":");
        System.Console.WriteLine(studentsTable.NechayLength);
        
        System.Console.WriteLine("____ Print out StudentsTable object Surname column:");

        Column surnameColumn = studentsTable[StudentsTable.SurnameColumn];

        for (int i = 0; i < surnameColumn.Length; i++)
        {
            System.Console.WriteLine(surnameColumn[i]);
        }
        
        System.Console.WriteLine("____ Print out StudentsTable object Name column:");

        Column nameColumn = studentsTable[StudentsTable.NameColumn];

        for (int i = 0; i < nameColumn.Length; i++)
        {
            System.Console.WriteLine(nameColumn[i]);
        }
        
        System.Console.WriteLine("____ Print out StudentsTable object Patronymic column:");

        Column patronymicColumn = studentsTable[StudentsTable.PatronymicColumn];

        for (int i = 0; i < patronymicColumn.Length; i++)
        {
            System.Console.WriteLine(patronymicColumn[i]);
        }
    }
}