// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++){
        for (int j = i + 1; j < len; j++){
            if (arr[i] != arr[j] && arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int i = 0, j = len - 1;
    while (arr[i] < arr[j]){
        while (arr[i] < arr[j]){
            if (arr[i] != arr[j]){
                if (arr[i] + arr[j] < value)
                    break;
                else if (arr[i] + arr[j] == value)
                    count++;
                j--;
            }
        }
        j = len - 1;
        i++;
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int left = 0, right = len - 1, middle, count = 0, i = 0;
    int pseudoValue = value - arr[0];
    if (pseudoValue <= 0)
        return 0;
    for (i = 0; i < len; i++){
        pseudoValue = value - arr[i];
        if (pseudoValue <= 0)
            break;
        left = i;
        right = len - 1;
        if (arr[left] <= pseudoValue && pseudoValue <= arr[right]){
            while (left <= right){
                middle = (left + right) / 2;
                if (arr[middle] == pseudoValue){
                    count++;
                    int buff = middle + 1;
                    while (buff < len && arr[buff] == pseudoValue){
                        count++;
                        buff++;
                    }
                    buff = middle - 1;
                    while (buff >= 0 && arr[buff] == pseudoValue){
                        count++;
                        buff--;
                    }
                    break;
                }
                else if (pseudoValue < arr[middle])
                    right = middle - 1;
                else
                    left = middle + 1;
            }
        }
    }
    return count;
}
