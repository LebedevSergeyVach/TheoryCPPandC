import std.stdio;
import std.conv;
import core.memory;

// Функция для динамического выделения памяти, заполнения и вывода данных
void dynamicMemoryExample(int size)
{
    int[] arr = new int[size];

    foreach (i; 0 .. size)
    {
        arr[i] = i + 1;
    }

    writeln("Динамически выделенный массив:");
    foreach (i, val; arr)
    {
        write(val, " ");
    }
    writeln();

    GC.free(arr.ptr);
}

void main()

{
    dynamicMemoryExample(15);
}
