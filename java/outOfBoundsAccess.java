public class outOfBoundsAccess {
	
	public static void main(String[] args) {
		final int[] numbers = new int[]{1,2,4,5};
		System.out.println(numbers[5]);
	}

}