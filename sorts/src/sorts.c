void insertion_sort(int *array, int length) {
    int key, i, j;

    for (i=1; i<length; i++) {
        key = array[i];

        for (j=i-1; array[j]>key && j>=0; j--) {
            array[j+1] = array[j];
        }

        array[j+1] = key;
    }
}
