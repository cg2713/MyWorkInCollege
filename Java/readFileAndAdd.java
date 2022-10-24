import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class readFileAndAdd {


   public static void main(String[] args) {

       try{
           //reading the file
           File file = new File("../readFileAndAdd/src/sum.txt");
           Scanner myScan = new Scanner(file);
            // reading the file line by line
           while (myScan.hasNextLine()){
               String nLine = myScan.nextLine();

               //Placing the one line that was read in to a string
               String numFile = new String(nLine);
               //Reading the string but breaking it to words/individual string numbers
               Scanner myNumScan = new Scanner(numFile);
               //initializing BigInterger since there is a number too big for a double
               BigInteger math = new BigInteger("0");

               // Reading one number string at a time from the line that was saved as a string
               while(myNumScan.hasNextBigInteger()){
                //storing the one number that was read in to "data" variable
                   BigInteger data = myNumScan.nextBigInteger();
                   System.out.printf("%s", data);
                   //printing out a plus symbol only if there is another up coming number
                   if(myNumScan.hasNextDouble()== true){

                       System.out.print(" + ");


                   }
                   // adding all the values of each number on that one line that is being read as numbers
                    math = math.add(data);


               }
               //prints out the result of all the added numbers of one line inside that file.
               System.out.printf( " = %s\n",math);



           }

            //stops scanning since there are no further lines to scan
           myScan.close();
       } catch (FileNotFoundException e) {
           e.printStackTrace();
       }

   }
}
