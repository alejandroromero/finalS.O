using System;
using System.Threading;

class gerph
{
    bool[] test = new bool[5];
    public void Get(int izq, int der)
    {
        lock (this)
        {
            while (test[izq] || test[der]) Monitor.Wait(this);
            test[izq] = true; test[der] = true;
        }
    }
    public void insrt(int izq, int der)
    {
        lock (this)
        {
            test[izq] = false; test[der] = false;
            Monitor.PulseAll(this);
        }
    }
}
class Philo
{
    int n;
    int retrasop;
    int retrasoc;
    int izq, der;
    gerph gerph;
    public Philo(int n, int retrasop, int retrasoc, gerph gerph)
    {
        this.n = n;
        this.retrasop = retrasop; this.retrasoc = retrasoc;
        this.gerph = gerph;
        izq = n == 0 ? 4 : n - 1;
        der = (n + 1) % 5;
        new Thread(new ThreadStart(Run)).Start();
    }
    public void Run()
    {
        for (; ; )
        {
            try
            {
                Thread.Sleep(retrasop);
                gerph.Get(izq, der);
                Console.WriteLine("Filosofo " + n + " esta comiendo...");
                Console.ReadLine();
                Thread.Sleep(retrasoc);
                gerph.insrt(izq, der);
            }
            catch
            {
                return;
            }
        }
    }

}
public class folosofos
{
    public static void Main()
    {
        gerph gerph= new gerph();
        new Philo(0, 10, 50, gerph);
        new Philo(1, 20, 40, gerph);
        new Philo(2, 30, 30, gerph);
        new Philo(3, 40, 20, gerph);
        new Philo(4, 50, 10, gerph);
    }
}
// En base en http://www.sanfoundry.com/csharp-program-dining-philosopher-problem/ //