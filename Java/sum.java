public class sum{
	public static void main(String[] args){
		int[] integer = new int[25];
		int[] integer2 = new int[25];
		int[] result = new int[25];
		
		int num = 16;
		int num2 = 19;
		
		convert(integer, num);
		convert(integer2, num2);
		
		printA(integer2);
		printA(integer);
		
		for(int i = 24; i > 0; i--){
			if((integer2[i] + integer[i]) != 0){
				result[i] += (integer2[i] + integer[i]) % 10;
				System.out.printf("%d\n", result[i]);
				if((integer2[i] + integer[i]) != 0 && (integer2[i] + integer[i]) <= 18){
					result[i-1] = 1;
				}
				
			}
			else{
				continue;
				//result[i] += integer2[i] + integer[i];
			}
		}
		printA(result);
		
		
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
	
	
	
}