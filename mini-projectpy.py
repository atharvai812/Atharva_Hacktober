import numpy as np
import threading
import time

def matrix_multiply(matrix1, matrix2, result, row_start, row_end):
    for i in range(row_start, row_end):
        for j in range(matrix2.shape[1]):
            result[i][j] = sum(matrix1[i, k] * matrix2[k, j] for k in range(matrix1.shape[1]))

# Function to perform single-threaded matrix multiplication
def single_threaded_matrix_multiplication(matrix1, matrix2):
    result = np.zeros((matrix1.shape[0], matrix2.shape[1]))
    matrix_multiply(matrix1, matrix2, result, 0, matrix1.shape[0])
    return result

# Function to perform multithreaded matrix multiplication with one thread per row
def multithreaded_matrix_multiplication_row(matrix1, matrix2, num_threads):
    result = np.zeros((matrix1.shape[0], matrix2.shape[1]))
    threads = []

    # Split the rows evenly among the threads
    chunk_size = matrix1.shape[0] // num_threads

    for i in range(num_threads):
        start_row = i * chunk_size
        end_row = start_row + chunk_size if i < num_threads - 1 else matrix1.shape[0]
        thread = threading.Thread(target=matrix_multiply, args=(matrix1, matrix2, result, start_row, end_row))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    return result

# Function to perform multithreaded matrix multiplication with one thread per cell
def multithreaded_matrix_multiplication_cell(matrix1, matrix2, num_threads):
    result = np.zeros((matrix1.shape[0], matrix2.shape[1]))
    threads = []

    for i in range(num_threads):
        thread = threading.Thread(target=calculate_cells, args=(matrix1, matrix2, result, i, num_threads))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    return result

# Function to calculate cells for multithreaded matrix multiplication with one thread per cell
def calculate_cells(matrix1, matrix2, result, thread_id, num_threads):
    rows, cols = matrix1.shape[0], matrix2.shape[1]
    for i in range(thread_id, rows, num_threads):
        for j in range(cols):
            result[i][j] = sum(matrix1[i, k] * matrix2[k, j] for k in range(matrix1.shape[1]))

if __name__ == "__main__":
    matrix_size = 100
    matrix1 = np.random.rand(matrix_size, matrix_size)
    matrix2 = np.random.rand(matrix_size, matrix_size)

    # Single-threaded matrix multiplication
    start_time = time.time()
    result_single = single_threaded_matrix_multiplication(matrix1, matrix2)
    single_threaded_time = time.time() - start_time

    # Multithreaded matrix multiplication with one thread per row
    num_threads = 4  
    start_time = time.time()
    result_row_threaded = multithreaded_matrix_multiplication_row(matrix1, matrix2, num_threads)
    multithreaded_row_time = time.time() - start_time

    # Multithreaded matrix multiplication with one thread per cell
    start_time = time.time()
    result_cell_threaded = multithreaded_matrix_multiplication_cell(matrix1, matrix2, num_threads)
    multithreaded_cell_time = time.time() - start_time

    print(f"Single-threaded time: {single_threaded_time:.4f} seconds")
    print(f"Multithreaded (one thread per row) time: {multithreaded_row_time:.4f} seconds")
    print(f"Multithreaded (one thread per cell) time: {multithreaded_cell_time:.4f} seconds")
    print(f"Results are equal (one thread per row): {np.allclose(result_single, result_row_threaded)}")
    print(f"Results are equal (one thread per cell): {np.allclose(result_single, result_cell_threaded)}")
