import matplotlib.pyplot as plt
import numpy as np

def read_input_file(file_path):
    with open(file_path, "r") as file:
        return [float(line.strip()) for line in file.readlines()]

file_names = ['HeapSort.txt', 'MergeSort.txt', 'QuickSort.txt', 'Sort.txt', 'Sortpy.txt']

all_data = [read_input_file(f"./{file}") for file in file_names]

bar_width = 0.15
num_rows = len(all_data[0])
indices = np.arange(num_rows)

colors = ['blue', 'green', 'orange', 'red', 'purple']
plt.figure(figsize=(10, 6))

for i, data in enumerate(all_data):
    plt.bar(indices + i * bar_width, data, width=bar_width, color=colors[i], label=file_names[i])


plt.xlabel("Test Case")
plt.ylabel("Thời gian thực hiện(ms)")
plt.title("So sánh thời gian thực hiện các thuật toán sắp xếp")
plt.xticks(indices + bar_width, [str(i+1) for i in range(0, 10)])
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.7)

plt.show()