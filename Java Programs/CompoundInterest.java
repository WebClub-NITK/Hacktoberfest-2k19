public class CompoundInterest {
  public static void main(String[] args) {
    //Assign the principle, rate and time
      double p, r, t, A=0.0, i;
      p = 5400;
      r = 5;
      t = 2;
      A = p*Math.pow((1 + r/100),t);
      i = A - p;
      System.out.println("Compound Interest = "+i);
  }
}
