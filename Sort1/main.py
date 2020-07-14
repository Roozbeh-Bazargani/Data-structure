import matplotlib.pyplot as plt
import numpy as np
import time
from random import randint
from copy import deepcopy

# heap sort ------------------------------------
def max_heapify(A,i,heapsize):
    l = 2*i + 1
    r = 2*(i + 1)
    if l < heapsize and A[l] > A[i]:
        largest = l
    else:
        largest = i
    if r < heapsize and A[r] > A[largest]:
        largest = r
    if largest != i:
        exchange(A,i,largest)
        max_heapify(A,largest,heapsize)

def Build_max_heap(A):
    for i in range(int((len(A) - 1) / 2), -1, -1):
        max_heapify(A, i, len(A))

def exchange(A,a,b):
    temp = A[a]
    A[a] = A[b]
    A[b] = temp

def Sort_Heap(A):
    Build_max_heap(A)
    heapsize = len(A)
    for i in range(len(A) - 1, 0, -1):
        exchange(A,0,i)
        heapsize = heapsize - 1
        max_heapify(A,0,heapsize)



# Insertion sort ----------------------------
def Sort_Insertion(A):
    n = len(A)
    for i in range(1,n):
        key = A[i]
        j = i - 1
        while (j > -1) & (A[j] > key):
            A[j + 1] = A[j]
            j = j - 1
        A[j + 1] = key


# Merge sort ---------------------------------
def Sort_Merge(A, p, r):
    if r > p:
        q = int((r + p) / 2)
        Sort_Merge(A, p, q)
        Sort_Merge(A, q + 1, r)
        merge(A, p, q, r)


def merge(A, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    L = [1e10] * (n1 + 1)
    R = [2e10] * (n2 + 1)
    for i in range(n1):
        L[i] = A[p + i]
    for j in range(n2):
        R[j] = A[q + j + 1]
    i = 0
    j = 0
    for k in range(p,r+1):
        if L[i] < R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1


# Randomized quicksort -----------------------------
def Sort_RandomizedQuicksort(A,p,r):
    if p < r:
        q = randomized_partition(A,p,r)
        Sort_RandomizedQuicksort(A,p,q - 1)
        Sort_RandomizedQuicksort(A, q + 1, r)

def randomized_partition(A,p,r):
    # i = randint(p,r)
    # exchange(A,r,i)
    return partition(A,p,r)

def partition(A,p,r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i = i + 1
            exchange(A, i, j)
    exchange(A, i + 1, r)
    return i + 1


# main ----------------------------------------
sizes = [2000, 2250, 2500, 2750, 3000, 5000, 7000, 10000]
t_insertion, t_merge, t_heap, t_quick = [], [], [], []
for size in sizes:
    arr = np.random.normal(10,10,size)
    arr1, arr2, arr3, arr4 = deepcopy(arr), deepcopy(arr), deepcopy(arr), deepcopy(arr)

    t0 = time.time()
    Sort_Insertion(arr1)
    t_insertion.append(time.time() - t0)

    t0 = time.time()
    Sort_Merge(arr2,0,len(arr2) - 1)
    t_merge.append(time.time() - t0)

    t0 = time.time()
    Sort_Heap(arr3)
    t_heap.append(time.time() - t0)

    t0 = time.time()
    Sort_RandomizedQuicksort(arr4, 0, len(arr4) - 1)
    t_quick.append(time.time() - t0)
    # print(arr1)
    # print(arr2)
    # print(arr3)
    # print(arr4)


sizes[:] = [x / 1000 for x in sizes]

plt.plot(sizes, t_insertion, 'k--', label='Insertion')
plt.plot(sizes, t_merge, 'b:', label='Merge')
plt.plot(sizes, t_heap, 'g-.', label='Heap')
plt.plot(sizes, t_quick, 'r-', label='Quick')

plt.xlabel('Size(*1000)')
plt.ylabel('time(second)')

plt.title("Sort methods Comparison")

plt.legend()

plt.show()


plt.plot(sizes, t_merge, 'b:', label='Merge')
plt.plot(sizes, t_heap, 'g-.', label='Heap')
plt.plot(sizes, t_quick, 'r-', label='Quick')

plt.xlabel('Size(*1000)')
plt.ylabel('time(second)')

plt.title("Sort methods Comparison")

plt.legend()

plt.show()