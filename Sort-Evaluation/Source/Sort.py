import numpy as np
import time
import os

def read_input_file(file_path):
    with open(file_path, "r") as file:
        data = file.read().strip().split()
    return [int(float(x)) for x in data]


input_files = [ f"../Make_Test/test{i}.inp" for i in range (1, 11)]

for file_path in input_files:
    arr = read_input_file(file_path)
    arr = np.array(arr)

    start = time.time()
    np.sort(arr)
    stop = time.time()

    delta_time = (stop - start) * 1000

    print(f"{delta_time:.2f}")


