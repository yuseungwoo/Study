
public class quick_sort {

	void quick_s(int[] arr, int start_index, int end_index) {
		//System.out.println();
		if(start_index >= end_index)
			return;

		int middle_index = (start_index + end_index) >> 1;
		int left_index = start_index , right_index = end_index;
		int middle_element = arr[middle_index];


		while(left_index < right_index) {

		while(arr[left_index] <= middle_element && left_index != middle_index) {
		    left_index++;

		}
		while(arr[right_index] >= middle_element &&  right_index != middle_index) {
			right_index--;

		}

		if(left_index < right_index) {
			//System.out.println(arr[left_index]+ " <-> "+ arr[right_index]);
			int tmp_ele = arr[left_index];
			arr[left_index] = arr[right_index];
			arr[right_index] = tmp_ele;

			if(middle_index == left_index)
				middle_index = right_index;

			else if(middle_index == right_index)
				middle_index = left_index;
		 }

		}
		quick_s(arr, start_index , middle_index - 1);
		quick_s(arr, middle_index + 1 , end_index);

	}

	public static void main(String[] args) {

		quick_sort q_s = new quick_sort();
		int[] arr = {5, 3,111,45,100, 10, 6 , 33, 5 , 3 , 10, 9 , 1, 123,1,4, 2};
		q_s.quick_s(arr, 0, arr.length-1);
		int count = 0 ;
		while(count != arr.length) {
			System.out.print(arr[count]+ " ");
			count ++;
		}


	}

}
