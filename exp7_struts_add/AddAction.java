public class AddAction {
    private int a, b, sum;
    public String execute() { sum = a + b; return "success"; }
    public int getA() { return a; }
    public void setA(int a) { this.a = a; }
    public int getB() { return b; }
    public void setB(int b) { this.b = b; }
    public int getSum() { return sum; }
}
