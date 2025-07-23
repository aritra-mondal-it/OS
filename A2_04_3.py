#!/usr/bin/python3   

#!/usr/bin/python3   

"""
"" 06/08/2025 ::: Ansh Kumar Singh(002311001073), Trisanjit Das(002311001089), Aritra Mondal(002311001091)
"" Section ::: A2
"" Team No ::: 04
"" Assignment ::: 4
""
"" Usage:
""     python3 A2_04_3.py <matrix_dim> <num_processes> <mod_value> <print_switch>
""
"" All Command Line Parameter Description:
""     <matrix_dim>      : Size of the square matrix (e.g., 3000)
""     <num_processes>   : Number of parallel processes to use (e.g., 4)
""     <mod_value>       : Modulo value to generate matrix elements randomly (e.g., 100)
""     <print_switch>    : 1 to print matrices; 0 to skip printing
""
"" What this Program Does:
""     This Python program performs matrix multiplication on two large randomly
""     initialized square matrices using multiprocessing to parallelize the work.
""     It measures the time taken for only the multiplication part using a high-
""     resolution timer and optionally prints the matrices.
""
"" Sample Input/Output Sets:                 
""     $ python3 A2_04_3.py 3000 4 100 0
""     Time taken for multiplication only: 54.5581 seconds
""
"" Input Details:
""     Randomly initialized matrices A and B of given dimension with elements in range [0, mod_value)
""
"" Output Details:
""     Time taken to multiply matrices (excluding initialization)
""     If print_switch is 1, prints matrices A, B, and the result matrix C
""
"" Time Taken ::: System Details:
""     Time measured using time.perf_counter()
""     CPU usage can be monitored externally using mpstat or sar
""
"" Requirements and Installation:
""     Python3 (install if missing):    $ sudo apt install python3
""     pip (Python package manager):   $ sudo apt install python3-pip
""     NumPy (required library):       $ pip install numpy
""
"""

import sys
import numpy as np
import multiprocessing as mp
import time

def worker(start_row, end_row, A, B, output_queue):
    result = np.dot(A[start_row:end_row], B)
    output_queue.put((start_row, result))

def parallel_matrix_multiply(A, B, num_processes):
    n = A.shape[0]
    output = mp.Queue()
    processes = []
    chunk = n // num_processes

    for i in range(num_processes):
        start = i * chunk
        end = n if i == num_processes - 1 else (i + 1) * chunk
        p = mp.Process(target=worker, args=(start, end, A, B, output))
        processes.append(p)
        p.start()

    C = np.zeros((n, n), dtype=np.uint32)

    for _ in processes:
        start_row, partial = output.get()
        C[start_row:start_row + partial.shape[0], :] = partial

    for p in processes:
        p.join()

    return C

def main():
    if len(sys.argv) != 5:
        print("Usage: python3 A3_04_3.py <matrix_dim> <num_processes> <mod_value> <print_switch>")
        sys.exit(1)

    n = int(sys.argv[1])
    num_processes = int(sys.argv[2])
    mod = int(sys.argv[3])
    print_switch = int(sys.argv[4])

    A = np.random.randint(0, mod, size=(n, n), dtype=np.uint32)
    B = np.random.randint(0, mod, size=(n, n), dtype=np.uint32)

    start = time.perf_counter()
    C = parallel_matrix_multiply(A, B, num_processes)
    end = time.perf_counter()

    print(f"Time taken for multiplication only: {end - start:.4f} seconds")

    if print_switch == 1:
        print("\nMatrix A:\n", A)
        print("\nMatrix B:\n", B)
        print("\nMatrix C = A x B:\n", C)

if __name__ == "__main__":
    mp.set_start_method('fork')  # Use 'spawn' on Windows if needed
    main()
