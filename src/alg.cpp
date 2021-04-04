// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
int count1 = 0;
for (int i = 0; i < len; i++) {
for (int j = i + 1; j < len; j++) {
if (arr[i] != arr[j] && arr[i] + arr[j] == value)
count1++;
}
}
return count1;
}
int countPairs2(int* arr, int len, int value) {
int count2 = 0;
int i = 0, j = len - 1;
while (arr[i] < arr[j]) {
while (arr[i] < arr[j]) {
if (arr[i] + arr[j] < value) {
break;
} else if (arr[i] + arr[j] == value) {
count2++;
int k = i + 1;
while (arr[k] + arr[j] == value) {
count2++;
k++;
}
}
j--;
}
i++;
}
return count2;
}
int countPairs3(int* arr, int len, int value) {
int left = 0, right = len - 1, middle, count3 = 0;
int pseudoValue;
for (int i = 0; i < len - 1; i++) {
pseudoValue = value - arr[i];
if (pseudoValue <= 0) {
break;
}
left = i + 1;
right = len - 1;
if (i == 90) {
int kek = 1 + 2;
}
if (arr[left] < pseudoValue && pseudoValue < arr[right]) {
while (left <= right) {
middle = (left + right) / 2;
if (arr[middle] == pseudoValue) {
count3++;
int buff = middle + 1;
while (buff < len && arr[buff] == pseudoValue) {
count3++;
buff++;
}
buff = middle - 1;
while (buff >= left && arr[buff] == pseudoValue) {
count3++;
buff--;
}
break;
} else {
if (pseudoValue < arr[middle])
right = middle - 1;
} else {
left = middle + 1;
}
}
}
}
return count3;
}
