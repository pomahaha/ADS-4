// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int schet = 0;
    for (int i = 0; i < len; i++)
        for (int v = i + 1; v < len; v++)
            if (arr[v] + arr[i] == value)
                schet++;
    return schet;
}
int countPairs2(int *arr, int len, int value) {
    int schet = 0, rt = len - 1;
    while (arr[rt] > value)
        rt--;
    for (int i = 0; i <= rt; i++)
        for (int v = i + 1; v <= rt; v++)
            if (arr[v] + arr[i] == value)
              schet++;
    return schet;
}
int cbinsearch(int *arr, int size, int value) {
  int schet = 0, lt = 0, rt = size - 1;
  while (lt <= rt) {
    int mdle =(rt - lt) / 2 + lt;
    if (arr[mdle] == value) {
        schet++;
        int i = 1 + mdle;
        while (i < size && arr[i] == value) {
            i++;
            schet++;
        }
        i = mdle - 1;
        while (i >= 0 && arr[i] == value) {
            i--;
            schet++;
        }
        break;
    }
    if (arr[mdle] < value)
        lt = 1 + mdle;
    if (arr[mdle] > value)
        rt = mdle - 1;
  }
  return schet;
}
int countPairs3(int *arr, int len, int value) {
    int schet = 0;
    int rt = len - 1;
    while (value < arr[rt])
        rt--;
    for (int i = 0; i <= rt; i++)
        schet += cbinsearch(arr + 1 + i, rt - i, value - arr[i]);
    return schet;
}
