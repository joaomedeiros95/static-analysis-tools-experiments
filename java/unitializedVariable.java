public class unitializedVariable {
	
	public static void main(String[] args) {
		final String text;
		final Integer x;
		final int[] someArray;

		final String anotherText = "something" + text;
		final int result = 10 + x + someArray[1];
	}

}