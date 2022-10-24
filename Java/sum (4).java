import java.io.*;
import java.util.Scanner;
public class sum{
	public static void main(String[] args){
		
		int[] integer = new int[25];
		int[] integer2 = new int[25];
		int[] result = new int[25];
		//System.out.printf("hit1");        //0
		String num = "999999999999999999999999";
		String num2 = "1";
		//System.out.printf("hit2");
		try{
			File file = new File("C:/Users/cgarcia/Desktop/sum.txt");
			Scanner input = new Scanner(file); 
		
			while (input.hasNext()) {
				String word  = input.next();
				System.out.println(word);
			}
			
		}
		catch (FileNotFoundException e) {
           e.printStackTrace();
		} 
		try{
			File file = new File("C:/Users/cgarcia/Desktop/sum.txt");
			BufferedReader br = new BufferedReader(new FileReader(file)); 
			String st;
			try {
				while ((st = br.readLine()) != null) {
					System.out.printf("%s\n\n",st); 
				}
			}
			catch(IOException e) {
					e.printStackTrace();
			}
		}
		catch (FileNotFoundException e) {
           e.printStackTrace();
		}
			
		
		/*
		AtoI(integer, num);
		AtoI(integer2, num2);
		//System.out.printf("hit3");
		//convert(integer, num);
		//convert(integer2, num2);
		
		//System.out.printf("hit4");
		addA(result, integer, integer2);
		//System.out.printf("hit5");
		System.out.printf("interger1 = ");
		printA(integer);
		
		System.out.printf("interger2 = ");
		printA(integer2);
		
		System.out.printf("result    = ");
		printA(result);
		//System.out.printf("hit6");*/
		
	}
	
	public static void AtoI(int[] number, String num){
		int j = 24;
		for(int i = num.length()-1; (i+1) > 0; i--){
			char temp = num.charAt(i);
			number[j] = Integer.parseInt(String.valueOf(temp));
			j--;
		}
	}
	
	public static void convert(int[] number, int num){
		for(int i = 24; i > 0; i--){
			number[i] = num % 10;
			num = num / 10;
			//num = num % 10;
		}
	}
	
	public static void printA(int[] number){
		for(int i = 0; i < 25; i++){
			System.out.printf("%d", number[i]);
		}
		System.out.printf("\n");
	}
	
	public static void addA(int[] number, int[] number2, int[] number3){
		for(int i = 24; i >= 0; i--){
			//56 44
			if((number2[i] + number3[i]) != 0){
				number[i] += (number2[i] + number3[i]) % 10;
				//System.out.printf("%d\n", number[i]);
				if(number[i] / 10 == 1){
					number[i] = 0;
					number[i-1] += 1;
					//System.out.printf("%d\n", number[i]);
				}
				else if((number2[i] + number3[i]) > 9 || (number2[i] + number3[i]) % 10 == 0){
					number[i-1] += 1;
					//System.out.printf("%d\n", number[i]);
				}
				//System.out.printf("%d\n", number[i]);
			}
			//System.out.printf("%d\n", number[i]);
		}
	}	
}