/*
 * binary_search implements the binary search algorithm on an array of integers,
 * assuming the array is already sorted
 */
int binary_search(int input[], int low, int high, int key)
{
	int mid;

	if (high < low) {
		return -1;
	}

	mid = low + ((high - low) / 2);

	if (input[mid] == key) {
		return mid;
	}

	if (key < input[mid]) {
		return binary_search(input, low, mid-1, key);
	} else {
		return binary_search(input, mid+1, high, key);
	}
}
