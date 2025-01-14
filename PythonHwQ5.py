def moving_average_filter(signal, window_size):

    if window_size <= 0:
        print("Error: Window size must be greater than 0.")
        return []
    if window_size > len(signal):
        print("Error: Window size must be smaller than or equal to the signal length.")
        return []
    
    smoothed_signal = []

    for i in range(len(signal) - window_size + 1):
        window = signal[i:i + window_size]
        average = sum(window) / window_size
        smoothed_signal.append(average)
    
    return smoothed_signal

#Example
signal = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
window_size = 2
smoothed_signal = moving_average_filter(signal, window_size)
print("Original Signal:", signal)
print("Smoothed Signal:", smoothed_signal)