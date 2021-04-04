// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value)
{
int cnt = 0;
for (int i = 0; i < len - 1; i++) {
for (int j = i + 1; j < len; j++) {
if (arr[i] + arr[j] == value) {
cnt++;
}
}
}
return cnt;
}
int countPairs2(int* arr, int len, int value)
{
int cnt = 0, r = len - 1, l = 0, mid;
while (l < r - 1) {
mid = (l + r) / 2;
if (arr[mid] <= value) {
l = mid + 1;
} else {
r = mid;
}
}
int len2 = r - 1;
for (int i = len2; i >= 0; i--) {
for (int j = 0; j < i; j++) {
if (arr[i] + arr[j] == value) {
cnt++;
}
if (arr[i] + arr[j] > value) {
break;
}
}
}
return cnt;
}
int countPairs3(int* arr, int len, int value)
{
int left = 0, right = len - 1, middle, count = 0, i = 0;
int pseudoValue = value - arr[0];
if (pseudoValue <= 0)
return 0;
for (i = 0; i < len; i++)
{
pseudoValue = value - arr[i];
if (pseudoValue <= 0)
break;
left = i;
right = len - 1;
if (arr[left] <= pseudoValue && pseudoValue <= arr[right])
{
while (left <= right)
{
middle = (left + right) / 2;
if (arr[middle] == pseudoValue)
{
count++;
int buff = middle + 1;
while (buff < len && arr[buff] == pseudoValue)
{
count++;
buff++;
}
buff = middle - 1;
while (buff >= 0 && arr[buff] == pseudoValue)
{
count++;
buff--;
}
break;
} else if (pseudoValue < arr[middle]) {
right = middle - 1;
} else {
left = middle + 1;
}
}
}
}
return count;
}
