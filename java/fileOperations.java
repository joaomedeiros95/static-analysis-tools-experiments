import java.io.*;
public class fileOperations {

   static void readOne() throws IOException {
      FileInputStream in = new FileInputStream("../example.txt");
      if (in != null) {
         in.close();
      }

      int c;
      while ((c = in.read()) != -1) {
         System.out.println(c);
      }
   }

   static void readTwo() throws IOException {
      FileInputStream in = null;

      try {
         in = new FileInputStream("../example.txt");
         
         int c;
         while ((c = in.read()) != -1) {
            System.out.println(c);
         }
      }finally {
         if (in != null) {
            in.close();
            in.close();
         }
      }
   }

   static void readThree() throws IOException {
      FileInputStream in = null;

      in = new FileInputStream("../example.txt");
      
      int c;
      while ((c = in.read()) != -1) {
         System.out.println(c);
      }  
   }

   public static void main(String args[]) throws IOException {  
      readTwo();
      readOne();
      readThree();
   }
}