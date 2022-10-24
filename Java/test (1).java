public class test{
	public static void main(String[] args){
		if(hasMidPoint(2,10,6))
			System.out.print("True");
		else
			System.out.print("false");
	}
	
	public static boolean hasMidPoint(int a, int b, int c){
		int[] d = {a ,b ,c};
		sort(d);
		int midp = d[1];
		int mid = (d[0] + d[2])/2;
		if(mid == midp){
			return true;
		}
		else
			return false;
	}
	public static void sort(int a[]){
		for(int i = 0; i <= 2; i++){
			for(int j = 0; j <= 2; j++){
				if(a[j] < a[i]){
					int temp = a[j];
					a[j] = a[i];
					a[i] = temp;
				}
			}
		}
	}
}
