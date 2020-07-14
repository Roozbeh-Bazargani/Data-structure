from random import randint
import time
import matplotlib.pyplot as plt

# Counting Sort --------------------------
def countingsort(A, k):
    c = [0] * (k + 1)
    b = [0] * (len(A))
    for j in A:
        c[j] = c[j] + 1
    for i in range(1, k + 1):
        c[i] = c[i] + c[i - 1]
    for j in range(len(A) - 1,-1,-1):
        b[c[A[j]] - 1] = A[j]
        c[A[j]] = c[A[j]] - 1
    return b


# radix sort -----------------------------
def radixsort(A,d):
    # print('')
    for k in range(d - 1, -1, -1):
        c = [0] * (10)
        b = ['0'] * (len(A))
        for j in A:
            c[int(j[k])] = c[int(j[k])] + 1
        for i in range(1, 10):
            c[i] = c[i] + c[i - 1]
        for j in range(len(A) - 1, -1, -1):
            # print(c[int(A[j][k])])
            b[c[int(A[j][k])] - 1] = A[j]
            c[int(A[j][k])] = c[int(A[j][k])] - 1
        A = b
    return A



# bucket sort ---------------------------
def bucketsort(A):
    n = len(A)
    b = [[] for i in range(n)]
    for i in A:
        b[int(n * i / 1000)].append(i)
    for i in b:
        Sort_Insertion(i)
    A[:] = [j for sub in b for j in sub]

def Sort_Insertion(A):
    n = len(A)
    for i in range(1,n):
        key = A[i]
        j = i - 1
        while (j > -1) & (A[j] > key):
            A[j + 1] = A[j]
            j = j - 1
        A[j + 1] = key


# main ---------------------------------
sizes = [100,1000,2000,5000,7000,10000,20000]
ctime, rtime, btime = [], [], []
for size in sizes:
    arr = []
    for i in range(size):
        arr.append(randint(100,999)) # Optional
    arr1, arr2 = arr[:], arr[:]
    arr[:] = [str(x) for x in arr]
    t0 = time.time()
    arr1 = countingsort(arr1, 999)
    ctime.append(time.time() - t0)
    t0 = time.time()
    arr = radixsort(arr,3)
    rtime.append(time.time() - t0)
    t0 = time.time()
    bucketsort(arr2)
    btime.append(time.time() - t0)

# rtime[:] = [x / 3 for x in rtime]

plt.plot(sizes, ctime, 'b:', label='Counting_Sort')
plt.plot(sizes, rtime, 'g-.', label='Radix_Sort')
plt.plot(sizes, btime, 'r-', label='Bucket_Sort')

plt.xlabel('Size')
plt.ylabel('time(second)')

plt.title("Sort methods Comparison")

plt.legend()

plt.show()