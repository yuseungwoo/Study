
public class search {

	void sort(int[] arr) {
		for(int i =0; i < arr.length ; i++) {
			for(int j = i ; j < arr.length ; j++) {		   
				if( arr[i] > arr[j]) {
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}
	
	boolean search_bi(int[] arr,int element) {
		int [] tmp_arr = new int[arr.length];
		System.arraycopy(arr, 0, tmp_arr, 0, arr.length);
		sort(tmp_arr);
		
		int front=0, back= tmp_arr.length-1,index = back;
		while(index!=front){
			index = (front+back)>>1;

		if(tmp_arr[index] > element)
			back = index-1;
		else if(tmp_arr[index] < element)
			front = index+1;
		else
			return true;	
		}
		return false;
	}
	
	
	/*
	public static void main(String[] args) {
		search sear = new search();
		int[] arr = {5,8,4,3,13,7,55,1,3,10};
		System.out.println(sear.search_bi(arr, 53));
 	}
 	*/
}
