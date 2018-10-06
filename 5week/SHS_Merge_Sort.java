
public class Merge_Sort {

	void merge_s(int[] arr) {
		int[] tmp_arr = new int[arr.length];

		int jump_right = 1, jump_arr;

		while (jump_right < arr.length) {

			jump_arr = jump_right << 1;

			System.arraycopy(arr, 0, tmp_arr, 0, arr.length);

			int arr_index = 0, start_arr_index = 0, left_arr_index = 0, right_arr_index = 0;

			while (arr_index < arr.length) {

				right_arr_index = left_arr_index + jump_right;

				while (arr_index < start_arr_index + jump_arr) {

					if (right_arr_index > arr.length - 1) {
						arr_index = arr.length;
						break;
					}

					if (tmp_arr[left_arr_index] < tmp_arr[right_arr_index]) {
						arr[arr_index] = tmp_arr[left_arr_index];
						left_arr_index++;
					}

					else {
						arr[arr_index] = tmp_arr[right_arr_index];
						right_arr_index++;
					}

					arr_index++;

					if (left_arr_index == start_arr_index + jump_right) {
						int copy_length = start_arr_index + jump_arr - right_arr_index;

						if (start_arr_index + jump_arr > arr.length)
							copy_length = arr.length - right_arr_index;

						System.arraycopy(tmp_arr, right_arr_index, arr, arr_index, copy_length);
						arr_index = start_arr_index + jump_arr;
						break;
					}

					else if (right_arr_index == start_arr_index + jump_arr || right_arr_index == arr.length) {
						System.arraycopy(tmp_arr, left_arr_index, arr, arr_index,
								start_arr_index + jump_right - left_arr_index);
						arr_index = start_arr_index + jump_arr;
						break;
					}

				}

				start_arr_index += jump_arr;
				left_arr_index = start_arr_index;

			}

			jump_right = jump_right << 1;

		}

	}

	public static void main(String[] args) {
		Merge_Sort m_s = new Merge_Sort();
		int[] arr = { 90, 2, 1, 100, 5, 1, 44, 3, 77, 78, 89, 3, 33, 1111, 998 };
		System.out.println("arr.length : " + arr.length);
		m_s.merge_s(arr);

		int count = 0;
		while (count != arr.length) {
			System.out.print(arr[count] + " ");
			count++;
		}

	}
}
