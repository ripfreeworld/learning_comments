public class BagelClass
{
    public SortedSet<string> Toppings { get; set; }

    public BagelClass(SortedSet<string> toppings)
    {
        Toppings = toppings;
    }
}

public struct Bagel
{
    public SortedSet<string> Toppings { get; set; }

    public Bagel(SortedSet<string> toppings)
    {
        Toppings = toppings;
    }
}

public class Program
{
    static void ModifyStruct(Bagel p)
    {
        p.Toppings = new SortedSet<string> { "cream cheese" }; // 改的是参数副本
    }

    static void ModifyClass(BagelClass p)
    {
        p.Toppings = new SortedSet<string> { "cream cheese" };
    }

    public static void Main()
    {
        Func<int> MakeCounter()
        {
            int count = 0;
            return () => ++count;
        }

        var c1 = MakeCounter();
        Console.WriteLine(c1()); // 1
        Console.WriteLine(c1()); // 2
        Console.WriteLine(c1()); // 3

        SortedSet<string> t = new SortedSet<string>();
        t.Add("salt");

        Bagel a = new Bagel(t);
        BagelClass aClass = new BagelClass(t);

        ModifyStruct(a);
        ModifyClass(aClass);

        t.Add("onion");

        // optional check
        Console.WriteLine(string.Join(", ", a.Toppings));
    }
}
