class Expression
{
    private int _m_a;
    private int _m_b;
    private int _m_c;
    
    public Expression(int a = 0, int b = 0, int c = 0)
        {
            this._m_a = a;
            this._m_b = b;
            this._m_c = c;
        }

        /**
         * Get expression result
         */
        public float Get()
        {
            if (this._m_c == 0)
            {
                throw new System.DivideByZeroException(
                    "(8 * log(b - 1) - c) / (a * 2 + b / c) expression. Division by zero (c = 0). (a = "
                    + this._m_a + "; b = " + this._m_b + "; c = " + this._m_c + ")."
                );
            }

            float divider = (this._m_a * 2 + this._m_b / this._m_c);

            if (divider == 0)
            {
                throw new System.DivideByZeroException(
                    "(8 * log(b - 1) - c) / (a * 2 + b / c) expression. Division by zero ((a * 2 + b / c) = 0). (a = "
                    + this._m_a + "; b = " + this._m_b + "; c = " + this._m_c + ")."
                );
            }

            return (float) (8 * System.Math.Log(this._m_b - 1) - this._m_c) / divider;
        }

        /**
         * Get object a property value
         */
        public int GetA()
        {
            return this._m_a;
        }

        /**
         * Get object b property value
         */
        public int GetB()
        {
            return this._m_b;
        }

        /**
         * Get object c property value
         */
        public int GetC()
        {
            return this._m_c;
        }

        /**
         * Set value for object a property
         */
        public void SetA(int a)
        {
            this._m_a = a;
        }

        /**
         * Set value for object b property
         */
        public void SetB(int b)
        {
            this._m_b = b;
        }

        /**
         * Set value for object c property
         */
        public void SetC(int c)
        {
            this._m_c = c;
        }
};

class Application
{
    static void Main(string[] args)
    {
        const int LENGTH = 15;
        
        System.Random rand = new System.Random();

        Expression[] expressions = new Expression[LENGTH];

        for (int i = 0; i < LENGTH; i++)
        {
            int a = rand.Next();
            int b = rand.Next();
            int c = rand.Next();
            
            if (i == 0) {
                // Check first exception
                c = 0;
            } else if (i == 1) {
                // Check second exception
                a = 0;
                b = 0;
            }

            expressions[i] = new Expression(a, b, c);

            try {
                float result = expressions[i].Get();
                
                System.Console.WriteLine(
                    "(8 * log(b - 1) - c) / (a * 2 + b / c) = " + result
                    + ". (a = " + a + "; b = " + b + "; c = " + c + ")."
                );
            } catch (System.DivideByZeroException e) {
                System.Console.WriteLine(e.Message);
            } catch {
                System.Console.WriteLine("Something goes wrong.");
            }
        }
    }
}