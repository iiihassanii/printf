/**
 * print_number - handle string print
 * @fd: file descriptor
 * @num: number we wanna print
 * @written_chars: return value
 * Return: written charctars
 */

void print_number(int fd, int num, int *written_chars)
{
        char buffer[BUFFER_SIZE];
        int buffer_index = 0;
        int num_copy = num;
        int num_digits = 0;

        if (num < 0)
        {
                buffer[buffer_index++] = '-';
                num_digits++;
                num_copy = -num_copy;
        }

        do {
                buffer[buffer_index++] = '0' + (num_copy % 10);
                num_digits++;
                num_copy /= 10;
        } while (num_copy != 0);

        while (buffer_index > 0)
        {
                _simple_write(fd, &buffer[--buffer_index], 1);
                *written_chars += 1;
        }
}
