# 42-Lisbon-Common-Core-get_next_line
The get_next_line project is about implementing a function that reads from a file descriptor and returns one line at a time, including the newline character if present. The main goal is to handle buffered reading efficiently, manage memory dynamically, and preserve state between calls. This function must work reliably regardless of line length or the number of file descriptors used, without leaking memory or reading unnecessary data.

It involves working with low-level file I/O (read), managing buffers, handling partial reads, and storing the remainder of the input for future calls using static variables. In the bonus part, the function must be able to read from multiple file descriptors simultaneously without mixing up their states.

This project is a core part of the 42 Common Core curriculum and reinforces key concepts such as buffer management, dynamic memory allocation, persistent state handling, and file descriptor control in C.
